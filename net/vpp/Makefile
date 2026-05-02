PORTNAME=	vpp
DISTVERSIONPREFIX=	v
DISTVERSION=	26.02
CATEGORIES=	net

PATCH_SITES=	https://codeberg.org/tj/${PORTNAME}/commit/
PATCHFILES=	3589daf20b23f03d65c947268462fb3ccf2e202f.patch:-p1 \
		48bdb38afde8155c8e4e076f96e8b210ff901a62.patch:-p1 \
		9492e4ce370b821f579ec76213bbcf3a11baff9d.patch:-p1 \
		77ec2c53a9ef008aab3b70cc2d81fe1a6a611691.patch:-p1 \
		f76f37f4375f59a81b680a98c37b7e38276f1c18.patch:-p1 \
		60ef21adeccd7d9075aa8da25e66874eba9ec5f4.patch:-p1 \
		96449540f846b70ee648f1ebae7fc1c305a94422.patch:-p1 \
		a9a4da02d0a3df2942201bb659cd76884c1cc48f.patch:-p1 \
		393a710295728bc879d383e535551f3f58214238.patch:-p1 \
		d61ab2719a5109619bfdf0b458ab49b1a62ccce9.patch:-p1 \
		fafca3d1636624d298d400b35f452b40a2559a13.patch:-p1 \
		55c934b7f9af69939aeafb9aac9e492bcee2ab36.patch:-p1 \
		d3f3ae886af4dac7db2abf698ec754ce6e343ac9.patch:-p1 \
		36d758b6df23a3e068639cdb574c3250b54d5d6a.patch:-p1 \
		75943ef3cc2be32e8c5767423d60b28ab032a0c1.patch:-p1

MAINTAINER=	thj@freebsd.org
COMMENT=	VPP: A fast, scalable layer 2-4 multi-platform network stack
WWW=		https://fd.io

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

IGNORE_FreeBSD_13=	is not supported on FreeBSD 13.x due to missing timerfd library shim

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ply>0:devel/py-ply@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		bash:shells/bash \
		cmake:devel/cmake-core
LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim \
		libpcap.so:net/libpcap \
		librte_cryptodev.so:net/dpdk

USES=		gmake ninja:build python:build shebangfix ssl
USE_GITHUB=	yes
GH_ACCOUNT=	FDio
USE_LDCONFIG=	yes
SHEBANG_REGEX=	.*\.py$$

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
	(cd ${WRKSRC}/${BUILD_PATH}/lib/ && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/)

post-install:
	${FIND} ${STAGEDIR}${PREFIX}/lib/ -name *.so -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
