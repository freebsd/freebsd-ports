PORTNAME=	thefish
DISTVERSION=	0.6.8
CATEGORIES=	sysutils
MASTER_SITES=	https://codeberg.org/BSDforge/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Gtk+/ncurses rc.conf editor/management tool
WWW=		https://codeberg.org/BSDforge/${PORTNAME}

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz

USES=		gnome pkgconfig

USE_GNOME=	cairo gdkpixbuf2 gtk20
MAKE_ENV+=	WITH_GTK=yes

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/thefish \
		share/man/man1/thefish.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/thefish ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/thefish.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
