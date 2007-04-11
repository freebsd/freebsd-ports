# New ports collection makefile for:    nautilus2
# Date created:         		28th August 2000
# Whom:                 		ade, archie
#
# $FreeBSD$
#   $MCom: ports/x11-fm/nautilus/Makefile,v 1.127 2007/03/16 16:07:42 marcus Exp $
#

PORTNAME=	nautilus
PORTVERSION=	2.18.1
CATEGORIES=	x11-fm gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	File manager for the GNOME desktop

LIB_DEPENDS=	exif.12:${PORTSDIR}/graphics/libexif

INSTALLS_ICONS=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_XLIB=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gnomedesktop eel2 \
		librsvg2 desktopfileutils ltverhack
GNOME_DESKTOP_VERSION=2
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="${PTHREAD_LIBS} -L${LOCALBASE}/lib -L${X11BASE}/lib -liconv" \
		LIBPNG="-L${LOCALBASE}/lib -lpng -lz"
CONFIGURE_ARGS=	--with-freetype2-lib-place=${LOCALBASE}/lib \
		--with-freetype2-include-place=${LOCALBASE}/include/freetype2 \
		--enable-static
MAKE_ENV=	G_CHARSET_ALIAS="${LOCALBASE}/libdata/charset.alias"

OPTIONS=	TRACKER "Enable Tracker Search (sysutils/tracker)" Off

GCONF_SCHEMAS=	apps_nautilus_preferences.schemas

.include <bsd.port.pre.mk>

.if defined(WITH_TRACKER)
LIB_DEPENDS+=	trackerclient.0:${PORTSDIR}/sysutils/tracker
.else
CONFIGURE_ARGS+=--disable-tracker
.endif

post-install:
	${MKDIR} ${PREFIX}/lib/nautilus/extensions-1.0
	@-update-desktop-database

.include <bsd.port.post.mk>
