# $FreeBSD$

PORTNAME=	libva-intel-driver
PORTVERSION=	2.3.0
PORTREVISION=	2
CATEGORIES=	multimedia

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	f139dafa5917.patch:-p1 # for mesa-libs 18.3+

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	VAAPI legacy driver for Intel GMA 4500 (Gen4) or newer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	Only Intel GPUs on x86 are supported

BUILD_DEPENDS=	libva>=2.3.0_3:multimedia/libva
LIB_DEPENDS=	libva.so:multimedia/libva \
		libdrm_intel.so:graphics/libdrm

GNU_CONFIGURE=	yes
USES=		autoreconf compiler:c11 gmake libtool pkgconfig tar:bzip2

USE_GITHUB=	yes
GH_ACCOUNT=	intel
GH_PROJECT=	intel-vaapi-driver

PLIST_FILES=	lib/dri/i915_drv_video.so lib/dri/i965_drv_video.so

OPTIONS_DEFINE=	HYBRID

HYBRID_DESC=	Hybrid VP8 encoding on Gen7/8 and VP9 decoding on Gen7/8/9
HYBRID_RUN_DEPENDS=	${LOCALBASE}/lib/dri/hybrid_drv_video.so:multimedia/libva-intel-hybrid-driver
HYBRID_CONFIGURE_ENABLE=	hybrid-codec

post-patch:	.SILENT
# XXX Remove va_api_version hack after 2.4.0 update
	${REINPLACE_CMD} -e 's|driverdir|& --define-variable prefix=${PREFIX}|' \
		-e '/va_api_version/s/1\.4\.0/1.1.0/' \
		${WRKSRC}/configure.ac

post-install:
	${LN} -sf i965_drv_video.so ${STAGEDIR}${PREFIX}/lib/dri/i915_drv_video.so

.include <bsd.port.mk>
