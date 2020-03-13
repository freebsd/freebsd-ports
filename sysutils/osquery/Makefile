# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	osquery
PORTVERSION=	3.3.2
PORTREVISION=	8
CATEGORIES=	sysutils

MAINTAINER=	zi@FreeBSD.org
COMMENT=	SQL powered OS instrumentation, monitoring, and analytics

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=		fails to compile: the clang compiler does not support '-march=x86-64'

BUILD_DEPENDS=	thrift>=0.11.0:devel/thrift \
		bash>0:shells/bash \
		linenoise-ng>0:devel/linenoise-ng \
		rapidjson>0:devel/rapidjson \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR}
LIB_DEPENDS=	libaugeas.so:textproc/augeas \
		libboost_regex.so:devel/boost-libs \
		libfuzzy.so:security/ssdeep \
		libgflags.so:devel/gflags \
		libglog.so:devel/glog \
		libicuuc.so:devel/icu \
		librocksdb-lite.so:databases/rocksdb-lite \
		libthrift.so:devel/thrift-cpp \
		libzstd.so:archivers/zstd
RUN_DEPENDS=	ca_root_nss>0:security/ca_root_nss

USES=		cmake compiler:c++11-lib gnome libarchive libtool \
		python:2.7,build ssl
USE_GNOME=	libxml2
CONFIGURE_ENV+=	OSQUERY_BUILD_VERSION="${PORTVERSION}" HOME="${WRKDIR}" \
		SKIP_TESTS="yes" CC="${CC}" CXX="${CXX}" \
		SKIP_SMART=1
CMAKE_ARGS+=	-DFREEBSD=awesome -DCMAKE_SYSTEM_NAME="FreeBSD"
BLDDIR=		${WRKDIR}/.build/${PORTNAME}
TPVERSION=	3.0.0
USE_RC_SUBR=	${PORTNAME}d
USE_GITHUB=	yes
GH_ACCOUNT=	facebook ${PORTNAME}:tp
GH_PROJECT=	third-party:tp
GH_SUBDIR=	third-party:tp
GH_TAGNAME=	${TPVERSION}:tp

# Some options for things that bring in many dependencies
OPTIONS_DEFINE=	TSK AWS YARA LLDPD

TSK_DESC=		Build with sleuthkit support
TSK_LIB_DEPENDS=	libtsk.so:sysutils/sleuthkit
TSK_CONFIGURE_ENV_OFF=	SKIP_TSK=1

AWS_DESC=		Support logging to AWS Kinesis
AWS_LIB_DEPENDS=	libaws-cpp-sdk-core.so:devel/aws-sdk-cpp
AWS_CONFIGURE_ENV_OFF=	SKIP_AWS=1

YARA_DESC=		Build with YARA malware identification support
YARA_LIB_DEPENDS=	libyara.so:security/yara
YARA_CONFIGURE_ENV_OFF=	SKIP_YARA=1

LLDPD_DESC=		Support Link Layer Discovery Protocol
LLDPD_LIB_DEPENDS=	liblldpctl.so:net-mgmt/lldpd
LLDPD_CONFIGURE_ENV_OFF=SKIP_LLDPD=1

.include <bsd.port.pre.mk>

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

	${MKDIR} ${STAGEDIR}/var/db/osquery ${STAGEDIR}/var/log/osquery
	# The flags file must exist, even if empty. Using @sample
	# prevents a populated flags file from being nuked on upgrade.
	${TOUCH} ${STAGEDIR}${PREFIX}/etc/osquery.flags.sample \
		${STAGEDIR}${PREFIX}/etc/osquery.flags

.include <bsd.port.post.mk>
