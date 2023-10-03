PORTNAME=	foreign-cdm
PORTVERSION=	2
CATEGORIES=	www multimedia linux
MASTER_SITES=	https://arrowd.name/:cdm \
		https://dl.google.com/linux/deb/pool/main/g/google-chrome-stable/:widevine
DISTFILES=	cdm-${CDM_INT_HASH}.tar.gz:cdm \
		google-chrome-stable_${CHROME_VERSION}_amd64.deb:widevine

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	CDM agent for Chromium
WWW=		https://github.com/shkhln/foreign-cdm

LICENSE=	MIT

ONLY_FOR_ARCHS=	amd64

BUILD_DEPENDS=	cmake:devel/cmake-core \
		linux-c7-devtoolset>0:devel/linux-c7-devtoolset
RUN_DEPENDS=	linux_base-c7>0:emulators/linux_base-c7

USE_GITHUB=	yes
GH_ACCOUNT=	shkhln
GH_PROJECT=	foreign-cdm
GH_TAGNAME=	760e440839f4456373460dcb61cfa8e36618d310
GH_TUPLE=	capnproto:capnproto:928c8390d4d562bd32dc79a42eb64e9bdba572d8:capnproto/third_party/capnproto

MAKE_ENV=	LINUX_CC=/compat/linux/opt/rh/devtoolset-11/root/usr/bin/g++ \
		MAKE_JOBS_NUMBER=${MAKE_JOBS_NUMBER}

CHROME_VERSION=	116.0.5845.179-1
CDM_INT_HASH=	fef0b5aa1bd31efb88dfab804bdbe614f3d54f28

post-extract:
	${MV} ${WRKDIR}/*.h ${WRKSRC}/third_party/cdm/
	cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} data.tar.xz ${EXTRACT_AFTER_ARGS}

do-install:
	${MKDIR} ${STAGEDIR}${LINUXBASE}/usr/bin
	${INSTALL_PROGRAM} ${WRKSRC}/build/fcdm-worker ${STAGEDIR}${LINUXBASE}/usr/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/foreign-cdm
	${MV} ${WRKSRC}/build/fcdm-fbsd.so ${STAGEDIR}${PREFIX}/lib/foreign-cdm/
	${MKDIR} ${STAGEDIR}${PREFIX}/share/chromium
	${MV} ${WRKDIR}/opt/google/chrome/WidevineCdm ${STAGEDIR}${PREFIX}/share/chromium/
	${MKDIR} ${STAGEDIR}${LINUXBASE}/usr/lib/foreign-cdm
	${MV} ${STAGEDIR}${PREFIX}/share/chromium/WidevineCdm/_platform_specific/linux_x64/libwidevinecdm.so ${STAGEDIR}${LINUXBASE}/usr/lib/foreign-cdm

post-install:
	${LN} -s ${PREFIX}/lib/foreign-cdm/fcdm-fbsd.so ${STAGEDIR}${PREFIX}/share/chromium/WidevineCdm/_platform_specific/linux_x64/libwidevinecdm.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/foreign-cdm/fcdm-fbsd.so

.include <bsd.port.mk>
