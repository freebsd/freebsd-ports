PORTNAME=	mpvpaper
DISTVERSION=	1.7
CATEGORIES=	multimedia wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Video wallpaper for wlroots compositors
WWW=		https://github.com/GhostNaN/mpvpaper

LICENSE=	GPLv3

BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-egl.so:graphics/wayland \
		libmpv.so:multimedia/mpv

USES=		compiler:c11 gl meson pkgconfig
USE_GITHUB=	yes
USE_GL=		egl
GH_ACCOUNT=	GhostNaN
PLIST_FILES=	bin/${PORTNAME} \
		bin/${PORTNAME}-holder \
		share/man/man1/${PORTNAME}.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's/pidof/pgrep/' \
		${WRKSRC}/src/holder.c \
		${WRKSRC}/src/main.c

post-install:
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.man \
		${STAGEDIR}${PREFIX}/share/man/man1/${PORTNAME}.1

.include <bsd.port.mk>
