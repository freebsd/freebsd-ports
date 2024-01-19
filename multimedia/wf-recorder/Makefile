PORTNAME=	wf-recorder
DISTVERSION=	0.4.1
PORTREVISION=	1
CATEGORIES=	multimedia wayland
MASTER_SITES=	https://github.com/ammen99/wf-recorder/releases/download/v${DISTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Screen recorder for wlroots-based compositors
WWW=		https://github.com/ammen99/wf-recorder

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	scdoc:textproc/scdoc \
		wayland-protocols>=1.14:graphics/wayland-protocols \
		wayland-scanner:graphics/wayland
LIB_DEPENDS=	libavutil.so:multimedia/ffmpeg \
		libwayland-client.so:graphics/wayland

USES=		compiler:c++11-lang gl meson pkgconfig tar:xz
USE_GL=		gbm

PLIST_FILES=	bin/wf-recorder \
		share/man/man1/wf-recorder.1.gz
PORTDOCS=	README.md

OPTIONS_DEFINE=		DOCS PULSEAUDIO
OPTIONS_DEFAULT=	PULSEAUDIO

PULSEAUDIO_DESC=Audio recording via PulseAudio

PULSEAUDIO_LIB_DEPENDS=	libpulse-simple.so:audio/pulseaudio
PULSEAUDIO_MESON_ENABLED=	pulse

post-patch:
# Extract (snapshot) version from the port instead of meson.build
	@${REINPLACE_CMD} -i .nogit -e 's/git.found()/false/' \
		-e '/project_version/s/@0@/${DISTVERSIONFULL}/' \
		${WRKSRC}/meson.build

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
