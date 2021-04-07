PORTNAME=	wf-recorder
DISTVERSION=	0.2.1
CATEGORIES=	multimedia wayland
MASTER_SITES=	https://github.com/ammen99/wf-recorder/releases/download/v${DISTVERSION}/

PATCH_SITES=	https://github.com/ammen99/${PORTNAME}/commit/
PATCHFILES+=	78d6a60833aa.patch:-p1 # https://github.com/ammen99/wf-recorder/pull/88

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Screen recorder for wlroots-based compositors

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	scdoc:textproc/scdoc \
		wayland-protocols>=1.14:graphics/wayland-protocols \
		wayland-scanner:graphics/wayland
LIB_DEPENDS=	libavutil.so:multimedia/ffmpeg \
		libwayland-client.so:graphics/wayland

USES=		compiler:c++11-lang meson pkgconfig tar:xz

PLIST_FILES=	bin/wf-recorder \
		man/man1/wf-recorder.1.gz
PORTDOCS=	README.md

OPTIONS_DEFINE=		DOCS OPENCL PULSEAUDIO
OPTIONS_DEFAULT=	OPENCL PULSEAUDIO

OPENCL_DESC=	RGB to YUV conversion with the help of OpenCL
PULSEAUDIO_DESC=Audio recording via PulseAudio

OPENCL_BUILD_DEPENDS=	opencl>0:devel/opencl
OPENCL_LIB_DEPENDS=	libOpenCL.so:devel/ocl-icd
OPENCL_MESON_ENABLED=	opencl

PULSEAUDIO_LIB_DEPENDS=	libpulse-simple.so:audio/pulseaudio
PULSEAUDIO_MESON_ENABLED=	pulse

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
