PORTNAME=	dmenu-translate
DISTVERSION=	g20230526
CATEGORIES=	textproc

MAINTAINER=	nxjoseph@protonmail.com
COMMENT=	Quick text translation with dmenu
WWW=		https://github.com/NikitaIvanovV/dmenu-translate

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	gsed:textproc/gsed \
		notify-send:devel/libnotify \
		trans:textproc/translate-shell \
		xterm:x11/xterm

USE_GITHUB=	yes
GH_ACCOUNT=	NikitaIvanovV
GH_TAGNAME=	8cc717d3d3bec7f1d7db804e1c339362536b6e45

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=		WAYLAND X11
OPTIONS_DEFAULT=	WAYLAND X11
WAYLAND_DESC=		depend on x11/wmenu and x11/wl-clipboard for use with Wayland
X11_DESC=		depend on x11/dmenu and x11/xclip for use with X11

WAYLAND_RUN_DEPENDS=	wl-copy:x11/wl-clipboard \
			wmenu:x11/wmenu
X11_RUN_DEPENDS=	dmenu:x11/dmenu \
			xclip:x11/xclip

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
