# Created by: Manuel Creach <manuel.creach@me.com>
# $FreeBSD$

PORTNAME=	libva-intel-driver
PORTVERSION=	2.3.0
CATEGORIES=	multimedia

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	VAAPI intel driver

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libva.so:multimedia/libva \
		libdrm.so:graphics/libdrm
BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat

GNU_CONFIGURE=	yes
USES=		alias autoreconf compiler:c11 gmake libtool localbase \
		pkgconfig tar:bzip2
USE_GL=		gl

USE_GITHUB=	yes
GH_ACCOUNT=	intel
GH_PROJECT=	intel-vaapi-driver

PLIST_FILES=	lib/dri/i915_drv_video.so lib/dri/i965_drv_video.so

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	Driver for hardware present only on intel i386 and amd64 CPUs

OPTIONS_DEFINE=	HYBRID

HYBRID_DESC=	Hybrid codec support (e.g., VP9 decoding on Skylake)
HYBRID_RUN_DEPENDS=	${LOCALBASE}/lib/dri/hybrid_drv_video.so:multimedia/libva-intel-hybrid-driver
HYBRID_CONFIGURE_ENABLE=	hybrid-codec

post-patch:	.SILENT
	${REINPLACE_CMD} -e 's/-ldl//' \
		${WRKSRC}/src/Makefile.am
	${REINPLACE_CMD} -e 's|driverdir|& --define-variable prefix=${PREFIX}|' \
		${WRKSRC}/configure.ac

post-install:
	${LN} -sf i965_drv_video.so ${STAGEDIR}${PREFIX}/lib/dri/i915_drv_video.so

.include <bsd.port.mk>
