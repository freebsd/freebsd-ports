PORTNAME=	xdaliclock
DISTVERSION=	2.48
PORTREVISION=	1
CATEGORIES=	x11-clocks
MASTER_SITES=	https://www.jwz.org/${PORTNAME}/

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Rather neat animated clock (GL & GTK version)
WWW=		https://www.jwz.org/xdaliclock/

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz

USES=		desktop-file-utils gl gmake gnome pkgconfig xorg
USE_GL=		gl
USE_GNOME=	cairo gdkpixbuf2 gtk30
GLIB_SCHEMAS=	org.jwz.xdaliclock.gschema.xml
USE_XORG=	x11

GNU_CONFIGURE=	yes
CONFLICTS=	xdaliclock-classic
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
