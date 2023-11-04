PORTNAME=	libva-nvidia-driver
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.11
CATEGORIES=	multimedia

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	8e8d49e11772.patch:-p1 # https://github.com/elFarto/nvidia-vaapi-driver/pull/220
PATCHFILES+=	5dc46a5a2fab.patch:-p1 # https://github.com/elFarto/nvidia-vaapi-driver/pull/220
PATCHFILES+=	22be7754bee5.patch:-p1 # https://github.com/elFarto/nvidia-vaapi-driver/pull/220
PATCHFILES+=	119a5a3ac448.patch:-p1 # https://github.com/elFarto/nvidia-vaapi-driver/pull/220
PATCHFILES+=	39c08a61a888.patch:-p1 # https://github.com/elFarto/nvidia-vaapi-driver/pull/220
PATCHFILES+=	fc1afd905f8c.patch:-p1 # https://github.com/elFarto/nvidia-vaapi-driver/pull/220
PATCHFILES+=	97430842d11a.patch:-p1 # https://github.com/elFarto/nvidia-vaapi-driver/pull/220

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	NVDEC-based backend for VAAPI
WWW=		https://github.com/elFarto/nvidia-vaapi-driver

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	Unusable without nvidia-drm-kmod and libc6-shim

BUILD_DEPENDS=	libdrm>=2.4.60,1:graphics/libdrm \
		ffnvcodec-headers>=11.1.5.1:multimedia/ffnvcodec-headers \
		libva>=2.8.0:multimedia/libva

USES=		compiler:c11 gl meson pkgconfig
USE_GITHUB=	yes
USE_GL=		egl
GH_ACCOUNT=	elFarto
GH_PROJECT=	nvidia-vaapi-driver
PLIST_FILES=	lib/dri/nvidia-drm_drv_video.so

OPTIONS_DEFINE=	GSTREAMER
OPTIONS_DEFAULT=GSTREAMER

GSTREAMER_USES=		gstreamer:1
GSTREAMER_USE=		GSTREAMER=bad

post-patch-GSTREAMER-off:
	@${REINPLACE_CMD} 's/gstreamer-codecparsers-1\.0//' ${WRKSRC}/meson.build

.include <bsd.port.mk>
