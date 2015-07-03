# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	osquery
PORTVERSION=	1.4.7
CATEGORIES=	sysutils

MAINTAINER=	zi@FreeBSD.org
COMMENT=	SQL powered OS instrumentation, monitoring, and analytics

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	snappy>0:${PORTSDIR}/archivers/snappy \
		rocksdb>0:${PORTSDIR}/databases/rocksdb \
		thrift>0:${PORTSDIR}/devel/thrift \
		thrift-cpp>0:${PORTSDIR}/devel/thrift-cpp \
		bash>0:${PORTSDIR}/shells/bash \
		yara>0:${PORTSDIR}/security/yara \
		doxygen:${PORTSDIR}/devel/doxygen \
		${PYTHON_PKGNAMEPREFIX}MarkupSafe>0:${PORTSDIR}/textproc/py-MarkupSafe \
		${PYTHON_PKGNAMEPREFIX}psutil>0:${PORTSDIR}/sysutils/py-psutil \
		${PYTHON_PKGNAMEPREFIX}argparse>0:${PORTSDIR}/devel/py-argparse \
		${PYTHON_PKGNAMEPREFIX}pexpect>0:${PORTSDIR}/misc/py-pexpect \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:${PORTSDIR}/devel/py-Jinja2  \
		${PYTHON_PKGNAMEPREFIX}thrift>0:${PORTSDIR}/devel/py-thrift \
		${PYTHON_PKGNAMEPREFIX}pip>0:${PORTSDIR}/devel/py-pip
LIB_DEPENDS=	libboost_regex.so:${PORTSDIR}/devel/boost-libs \
		libgflags.so:${PORTSDIR}/devel/gflags \
		libicuuc.so:${PORTSDIR}/devel/icu

USES=		cmake:outsource gmake libtool python:build compiler:c++11-lib
CMAKE_ENV+=	OSQUERY_BUILD_VERSION="${PORTVERSION}" HOME="${WRKDIR}" \
		SKIP_TESTS="yes" CC="${CC}" CXX="${CXX}"
CMAKE_ARGS+=	-DFREEBSD=awesome -DCMAKE_SYSTEM_NAME="FreeBSD"
BLDDIR=		${WRKDIR}/.build/${PORTNAME}
USE_RC_SUBR=	${PORTNAME}d
USE_GITHUB=	yes
GH_ACCOUNT=	facebook ${PORTNAME}:tp
GH_PROJECT=	third-party:tp
MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} <= 1000000
CFLAGS+=	-D_GLIBCXX_USE_C99
.endif

post-extract:
	${RMDIR} ${WRKSRC}/third-party
	${LN} -sf ${WRKSRC_tp} ${WRKSRC}/third-party

post-patch:
	${REINPLACE_CMD} -e 's|/var/osquery|/var/db/osquery|g' \
		${WRKSRC}/osquery/core/init.cpp
	${REINPLACE_CMD} -e 's|/var/osquery/osquery.em|/var/run/osquery.em|g' \
		-e 's|/etc/osquery/extensions.load|${PREFIX}/etc/osquery.extensions|g' \
		-e 's|/etc/osquery/modules.load|${PREFIX}/etc/osquery.modules|g' \
		${WRKSRC}/osquery/extensions/extensions.cpp
	${REINPLACE_CMD} -e 's|/var/osquery/osquery.conf|${PREFIX}/etc/osquery.conf|g' \
		${WRKSRC}/osquery/config/plugins/filesystem.cpp
	${REINPLACE_CMD} -e 's|/var/osquery/|/var/db/osquery/|g' \
		${WRKSRC}/tools/deployment/osquery.example.conf
	${REINPLACE_CMD} -e 's|python |${PYTHON_CMD} |g' \
		${WRKSRC}/CMake/CMakeLibs.cmake \
		${WRKSRC}/CMakeLists.txt

do-install:
	${INSTALL_PROGRAM} ${BLDDIR}/osqueryi ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${BLDDIR}/osqueryd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${BLDDIR}/libosquery.a ${STAGEDIR}${PREFIX}/lib
	(cd ${WRKSRC}/include && ${COPYTREE_SHARE} ${PORTNAME} ${STAGEDIR}${PREFIX}/include)
	${INSTALL_DATA} ${WRKSRC}/tools/deployment/osquery.example.conf \
		${STAGEDIR}${PREFIX}/etc/osquery.conf.sample

post-stage:
	${MKDIR} ${STAGEDIR}/var/db/osquery

.include <bsd.port.post.mk>
