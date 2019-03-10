# $FreeBSD$

PORTNAME=	wf-recorder
DISTVERSION=	g20190226
CATEGORIES=	multimedia wayland

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Screen recorder for wlroots-based compositors

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>=1.14:graphics/wayland-protocols \
		wayland-scanner:graphics/wayland
LIB_DEPENDS=	libavutil.so:multimedia/ffmpeg \
		libwayland-client.so:graphics/wayland

USES=		meson pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	ammen99
GH_TAGNAME=	7cd6bd2779b1da68afd34dfb3fb63214d1aff7d9

PLIST_FILES=	bin/wf-recorder
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
