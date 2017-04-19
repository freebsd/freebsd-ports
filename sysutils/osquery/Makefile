# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	osquery
PORTVERSION=	2.4.0
CATEGORIES=	sysutils

MAINTAINER=	zi@FreeBSD.org
COMMENT=	SQL powered OS instrumentation, monitoring, and analytics

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	thrift>0:devel/thrift \
		bash>0:shells/bash \
		linenoise-ng>0:devel/linenoise-ng \
		asio>0:net/asio \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2
LIB_DEPENDS=	libaugeas.so:textproc/augeas \
		libboost_regex.so:devel/boost-libs \
		libgflags.so:devel/gflags \
		libglog.so:devel/glog \
		libicuuc.so:devel/icu \
		libthrift.so:devel/thrift-cpp \
		libtsk.so:sysutils/sleuthkit \
		libcppnetlib-uri.so:devel/cpp-netlib \
		librocksdb-lite.so:databases/rocksdb-lite \
		libyara.so:security/yara \
		liblldpctl.so:net-mgmt/lldpd

USES=		cmake:outsource gmake libtool python:build compiler:c++11-lib
CONFIGURE_ENV+=	OSQUERY_BUILD_VERSION="${PORTVERSION}" HOME="${WRKDIR}" \
		SKIP_TESTS="yes" CC="${CC}" CXX="${CXX}"
CMAKE_ARGS+=	-DFREEBSD=awesome -DCMAKE_SYSTEM_NAME="FreeBSD"
BLDDIR=		${WRKDIR}/.build/${PORTNAME}
USE_RC_SUBR=	${PORTNAME}d
USE_GITHUB=	yes
GH_ACCOUNT=	facebook ${PORTNAME}:tp
GH_PROJECT=	third-party:tp
GH_SUBDIR=	third-party:tp
MAKE_JOBS_UNSAFE=	yes

post-patch:
	${REINPLACE_CMD} -e 's|/var/osquery/|/var/db/osquery/|g' \
		${WRKSRC}/tools/deployment/osquery.example.conf
	${REINPLACE_CMD} -e 's|python|${PYTHON_CMD}|g' \
		${WRKSRC}/CMakeLists.txt \
		${WRKSRC}/tools/get_platform.py

do-install:
	${INSTALL_PROGRAM} ${BLDDIR}/osqueryi ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${BLDDIR}/osqueryd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${BLDDIR}/libosquery.a ${STAGEDIR}${PREFIX}/lib
	(cd ${WRKSRC}/include && ${COPYTREE_SHARE} ${PORTNAME} ${STAGEDIR}${PREFIX}/include)
	${INSTALL_DATA} ${WRKSRC}/tools/deployment/osquery.example.conf \
		${STAGEDIR}${PREFIX}/etc/osquery.conf.sample

	${MKDIR} ${STAGEDIR}/var/db/osquery
	${MKDIR} ${STAGEDIR}/var/log/osquery

.include <bsd.port.mk>
