PORTNAME=	xdaliclock
DISTVERSION=	2.46
CATEGORIES=	x11-clocks
MASTER_SITES=	https://www.jwz.org/${PORTNAME}/

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Rather neat animated clock

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz

USES=		gl gmake gnome pkgconfig
USE_GL=		gl
USE_GNOME=	cairo gdkpixbuf2 gtk30

GLIB_SCHEMAS=	org.jwz.xdaliclock.gschema.xml

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/X11

PLIST_FILES=	bin/xdaliclock \
		man/man1/xdaliclock.1.gz \
		share/applications/xdaliclock.desktop \
		share/glib-2.0/schemas/gschemas.compiled \
		share/pixmaps/xdaliclock.png

# workaround: missing share/glib-2.0/schemas in stage
pre-install:
	${MKDIR}	${STAGEDIR}/${PREFIX}/share/glib-2.0/schemas

.include <bsd.port.mk>
