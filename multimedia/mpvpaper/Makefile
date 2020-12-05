# $FreeBSD$

PORTNAME=	mpvpaper
DISTVERSION=	1.1
CATEGORIES=	multimedia

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Video wallpaper for wlroots compositors

LICENSE=	GPLv3

BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-egl.so:graphics/wayland \
		libmpv.so:multimedia/mpv

USES=		compiler:c11 gl meson pkgconfig
USE_GITHUB=	yes
USE_GL=		egl
GH_ACCOUNT=	GhostNaN
PLIST_FILES=	bin/${PORTNAME} \
		bin/${PORTNAME}-holder

post-patch:
	@${REINPLACE_CMD} 's/pidof/pgrep/' ${WRKSRC}/src/main.c

.include <bsd.port.mk>
