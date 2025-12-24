PORTNAME=	xdaliclock
DISTVERSION=	2.49
CATEGORIES=	x11-clocks
MASTER_SITES=	https://www.jwz.org/${PORTNAME}/

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Rather neat animated clock (GL & GTK version)
WWW=		https://www.jwz.org/xdaliclock/

LICENSE=	MIT # `head -n 12 ${WRKSRC}/X11/xdaliclock.c`

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz

USES=		desktop-file-utils gl gmake gnome pkgconfig xorg
USE_GL=		gl
USE_GNOME=	cairo gdkpixbuf gtk30
GLIB_SCHEMAS=	org.jwz.xdaliclock.gschema.xml
USE_XORG=	x11

GNU_CONFIGURE=	yes
CONFLICTS=	xdaliclock-classic
WRKSRC=		${WRKDIR}/${DISTNAME}/X11

PLIST_FILES=	bin/xdaliclock \
		share/applications/xdaliclock.desktop \
		share/glib-2.0/schemas/gschemas.compiled \
		share/man/man1/xdaliclock.1.gz \
		share/pixmaps/xdaliclock.png

# workaround: missing share/glib-2.0/schemas dir in stage
pre-install:
	${MKDIR}	${STAGEDIR}/${PREFIX}/share/glib-2.0/schemas

.include <bsd.port.mk>
