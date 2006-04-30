# New ports collection makefile for:    nautilus2
# Date created:         		28th August 2000
# Whom:                 		ade, archie
#
# $FreeBSD$
#   $MCom: ports/x11-fm/nautilus2/Makefile,v 1.105 2006/04/13 07:52:42 bland Exp $
#

PORTNAME=	nautilus2
PORTVERSION=	2.14.1
CATEGORIES=	x11-fm gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/2$//}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DISTNAME=	nautilus-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	File manager for the GNOME desktop

LIB_DEPENDS=	exif.12:${PORTSDIR}/graphics/libexif

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gnomedesktop eel2 \
		librsvg2 desktopfileutils
GNOME_DESKTOP_VERSION=2
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="${PTHREAD_LIBS} -L${LOCALBASE}/lib -L${X11BASE}/lib -liconv" \
		LIBPNG="-L${LOCALBASE}/lib -lpng -lz"
CONFIGURE_ARGS=	--with-freetype2-lib-place=${LOCALBASE}/lib \
		--with-freetype2-include-place=${LOCALBASE}/include/freetype2 \
		--enable-static
MAKE_ENV=	G_CHARSET_ALIAS="${LOCALBASE}/libdata/charset.alias"

GCONF_SCHEMAS=	apps_nautilus_preferences.schemas

post-install:
	${MKDIR} ${PREFIX}/lib/nautilus/extensions-1.0
	@-update-desktop-database
#	@${CHMOD} u+w ${PREFIX}/share/gnome/nautilus/*.desktop

.include <bsd.port.mk>
