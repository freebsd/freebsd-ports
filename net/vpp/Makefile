PORTNAME=	vpp
DISTVERSIONPREFIX=	v
DISTVERSION=	24.06
PORTREVISION=	1
CATEGORIES=	net

PATCH_SITES=	https://github.com/adventureloop/${PORTNAME}/commit/
PATCHFILES=	fba2754d78cde15f93d19f86499aa3803110bc73.patch:-p1 \
		c15618aa59bf39197c66ec2e82c58c02d4c56c20.patch:-p1 \
		b8e219b761d0e2cc1caf5196f0ebfaf8ea776b26.patch:-p1

MAINTAINER=	thj@freebsd.org
COMMENT=	VPP: A fast, scalable layer 2-4 multi-platform network stack
WWW=		https://fd.io

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

IGNORE_FreeBSD_13=	is not supported on FreeBSD 13.x due to missing timerfd library shim

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ply>0:devel/py-ply@${PY_FLAVOR} \
		bash:shells/bash \
		cmake:devel/cmake-core
LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim \
		libpcap.so:net/libpcap \
		librte_cryptodev.so:net/dpdk

USES=		gmake ninja:build python:build shebangfix ssl
USE_GITHUB=	yes
GH_ACCOUNT=	FDio
USE_LDCONFIG=	yes
SHEBANG_REGEX=	'.*\.py$$'

ALL_TARGET=	build-release

VPPPROGS=	vat2 vpp_json_test vpp_echo vpp_prometheus_export svmdbtool \
		vpp_get_metrics vpp_restart svmtool vpp_get_stats vpp vppctl
BUILD_PATH=	build-root/build-vpp-native/vpp

pre-configure:
	@${ECHO_CMD} ${DISTVERSION} > ${WRKSRC}/src/scripts/.version

do-install:
# vpp_find_plugin_path hard codes in a search based on the vpp path to
# find vpp_plugsins and explicitly looks for 'bin' (src/vpp/vnet/main.c)
.for vpp_prog in ${VPPPROGS}
	${INSTALL_PROGRAM} ${WRKSRC}/${BUILD_PATH}/bin/${vpp_prog} ${STAGEDIR}${PREFIX}/bin
.endfor
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/vpp_plugins ${STAGEDIR}${PREFIX}/lib/vat2_plugins
	${CP} ${WRKSRC}/${BUILD_PATH}/lib/vpp_plugins/* ${STAGEDIR}${PREFIX}/lib/vpp_plugins/
	${CP} ${WRKSRC}/${BUILD_PATH}/lib/vat2_plugins/* ${STAGEDIR}${PREFIX}/lib/vat2_plugins/
	${INSTALL_LIB} ${WRKSRC}/${BUILD_PATH}/lib/*.so* ${STAGEDIR}${PREFIX}/lib

post-install:
	${FIND} ${STAGEDIR}${PREFIX}/lib/ -name *.so -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
