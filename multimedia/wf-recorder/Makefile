PORTNAME=	wf-recorder
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.0
CATEGORIES=	multimedia wayland

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Screen recorder for wlroots-based compositors
WWW=		https://github.com/ammen99/wf-recorder

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	scdoc:textproc/scdoc \
		wayland-protocols>=1.14:graphics/wayland-protocols \
		wayland-scanner:graphics/wayland
LIB_DEPENDS=	libavutil.so:multimedia/ffmpeg \
		libdrm.so:graphics/libdrm \
		libwayland-client.so:graphics/wayland

USES=		compiler:c++11-lang gl meson pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	ammen99

USE_GL=		gbm

PLIST_FILES=	bin/wf-recorder \
		share/fish/fish/vendor_completions.d/wf-recorder.fish \
		share/man/man1/wf-recorder.1.gz
PORTDOCS=	README.md

OPTIONS_DEFINE=		DOCS PIPEWIRE PULSEAUDIO
OPTIONS_DEFAULT=	PIPEWIRE PULSEAUDIO

PIPEWIRE_DESC=		Audio recording via PipeWire
PULSEAUDIO_DESC=	Audio recording via PulseAudio

PIPEWIRE_LIB_DEPENDS=		libpipewire-0.3.so:multimedia/pipewire
PIPEWIRE_MESON_ENABLED=		pipewire
PULSEAUDIO_LIB_DEPENDS=		libpulse-simple.so:audio/pulseaudio
PULSEAUDIO_MESON_ENABLED=	pulse

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
