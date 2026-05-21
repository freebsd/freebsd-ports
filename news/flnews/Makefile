PORTNAME=	flnews
PORTVERSION=	1.3.0
CATEGORIES=	news
MASTER_SITES=	https://micha.freeshell.org/flnews/src/

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	Fast and lightweight Usenet newsreader with FLTK GUI
WWW=		https://micha.freeshell.org/flnews/

LICENSE=	FLNEWS
LICENSE_NAME=	flnews license (BSD-style with identification clause)
LICENSE_FILE=	${WRKSRC}/src/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk

USES=		pkgconfig ssl tar:bzip2 xorg
USE_XORG=	x11 xcursor xext xfixes xft xinerama xrender

MAKE_ARGS=	PREFIX=${PREFIX}
INSTALL_TARGET=	install-strip

PLIST_FILES=	bin/flnews \
		share/applications/flnews.desktop \
		share/flnews/license.txt \
		share/icons/hicolor/48x48/apps/flnews.png \
		share/icons/hicolor/64x64/apps/flnews.png \
		share/man/man1/flnews.1.gz

OPTIONS_DEFINE=		XDG_UTILS
OPTIONS_DEFAULT=	XDG_UTILS

XDG_UTILS_DESC=		Use xdg-utils to open URLs and mail clients
XDG_UTILS_RUN_DEPENDS=	xdg-open:devel/xdg-utils

post-patch:
	@${REINPLACE_CMD} -e 's|^CFG_XDG_DISABLE=.*|CFG_XDG_DISABLE=0|' \
		-e 's|^CFG_NLS_DISABLE=.*|CFG_NLS_DISABLE=1|' \
		${WRKSRC}/CONFIG

.include <bsd.port.mk>
