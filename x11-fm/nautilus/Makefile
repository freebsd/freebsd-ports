# New ports collection makefile for:    nautilus2
# Date created:         		28th August 2000
# Whom:                 		ade, archie
#
# $FreeBSD$
#   $MCom: ports-stable/x11-fm/nautilus/Makefile,v 1.4 2009/04/15 12:03:35 kwm Exp $
#

PORTNAME=	nautilus
PORTVERSION=	2.26.3
PORTREVISION=	1
CATEGORIES=	x11-fm gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT?=	File manager for the GNOME desktop

LIB_DEPENDS=	exif.12:${PORTSDIR}/graphics/libexif \
		unique-1.0.2:${PORTSDIR}/x11-toolkits/unique \
		exempi.3:${PORTSDIR}/textproc/exempi

INSTALLS_ICONS=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gnomedesktop \
		librsvg2 desktopfileutils ltverhack gvfs ltasneededhack
GNOME_DESKTOP_VERSION=2
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="${PTHREAD_LIBS} -L${LOCALBASE}/lib -liconv" \
		LIBPNG="-L${LOCALBASE}/lib -lpng -lz"
CONFIGURE_ARGS=	--enable-static
MAKE_ENV=	G_CHARSET_ALIAS="${LOCALBASE}/libdata/charset.alias"

OPTIONS=	TRACKER "Enable Tracker Search (sysutils/tracker)" Off

GCONF_SCHEMAS=	apps_nautilus_preferences.schemas

MAN1=		nautilus-connect-server.1 nautilus-file-management-properties.1 \
		nautilus.1

.include <bsd.port.pre.mk>

.if defined(WITH_TRACKER)
#RUN_DEPENDS+=	tracker-applet:${PORTSDIR}/sysutils/tracker-gnome		
LIB_DEPENDS+=	trackerclient.0:${PORTSDIR}/sysutils/tracker-client \
		tracker-gtk.0:${PORTSDIR}/sysutils/tracker-libtrackergtk
.else
CONFIGURE_ARGS+=--disable-tracker
.endif

post-install:
	@${MKDIR} ${PREFIX}/lib/nautilus/extensions-2.0
	@-update-desktop-database

.include <bsd.port.post.mk>
