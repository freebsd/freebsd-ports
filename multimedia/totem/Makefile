# New ports collection makefile for:    totem
# Date created:         17 Oct 2002
# Whom:                 Hendrik Scholz <hendrik@scholz.net>
#
# $FreeBSD$
#

PORTNAME=	totem
PORTVERSION=	1.4.0
CATEGORIES=	multimedia gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER?=	hendrik@scholz.net
COMMENT?=	A Xine-based video player for the Gnome 2 Desktop

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes
LIB_DEPENDS=	musicbrainz:${PORTSDIR}/audio/libmusicbrainz
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack gnomedesktop desktopfileutils \
		nautiluscdburner
GNOME_DESKTOP_VERSION=2
WANT_GSTREAMER=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
INSTALLS_OMF=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
	       	LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib -lXrandr"

OPTIONS?=	DVDNAV "Enable DVD support" on \
		GSTREAMER "Use Gstreamer instead of Xine" off \
		MOZILLA_PLUGIN "Totem mozilla plugin" off

MAN1=	totem.1 totem-video-thumbnailer.1
GCONF_SCHEMAS=	totem-handlers.schemas totem-video-thumbnail.schemas \
		totem.schemas
CONFLICTS?=	totem-gstreamer-[0-9]*

.include <bsd.port.pre.mk>

.if defined(WITH_MOZILLA_PLUGIN)
USE_GECKO=	firefox mozilla seamonkey
.include "${.CURDIR}/../../www/mozilla/bsd.gecko.mk"
PLIST_SUB+=	MOZILLA=""
LIB_DEPENDS+=	dbus-1.2:${PORTSDIR}/devel/dbus
CONFIGURE_ARGS+=--with-mozilla=${GECKO}
.else
PLIST_SUB+=	MOZILLA="@comment "
CONFIGURE_ARGS+=--disable-mozilla
.endif

.if defined(WITH_GSTREAMER)
CONFIGURE_ARGS+=--enable-gstreamer=0.10
USE_GSTREAMER+=	gnomevfs core gconf
WITHOUT_DVDNAV=	yes
PLIST_SUB+=	GSTREAMER=""
.else
LIB_DEPENDS+=	xine.15:${PORTSDIR}/multimedia/libxine
PLIST_SUB+=	GSTREAMER="@comment "
.endif

.if defined(WITH_DVDNAV) && !defined(WITHOUT_DVDNAV)
LIB_DEPENDS+=	dvdnav.4:${PORTSDIR}/multimedia/libdvdnav
.endif

.if defined(WITH_CDROM_DEVICE)
DEFAULT_CDROM_DEVICE=${WITH_CDROM_DEVICE}
.else
.if ${OSVERSION} < 500000
DEFAULT_CDROM_DEVICE=/dev/acd0c
.else
DEFAULT_CDROM_DEVICE=/dev/acd0
.endif
.endif

.if defined(WITH_DVD_DEVICE)
DEFAULT_DVD_DEVICE=${WITH_DVD_DEVICE}
.else
.if ${OSVERSION} < 500000
DEFAULT_DVD_DEVICE=/dev/acd0c
.else
DEFAULT_DVD_DEVICE=/dev/acd0
.endif
.endif

pre-everything::
	@${ECHO_MSG} "===> The default CDROM device is ${DEFAULT_CDROM_DEVICE}"
	@${ECHO_MSG} "===> Define WITH_CDROM_DEVICE if you want to change the default"
	@${ECHO_MSG} "===> For example, 'make WITH_CDROM_DEVICE=\"/dev/somedevice\"'"
	@${ECHO_MSG} "===>"
	@${ECHO_MSG} "===> The default DVD device is ${DEFAULT_DVD_DEVICE}"
	@${ECHO_MSG} "===> Define WITH_DVD_DEVICE if you want to change the default"
	@${ECHO_MSG} "===> For example, 'make WITH_DVD_DEVICE=\"/dev/somedevice\"'"

post-patch:
	@${CP} -f ${FILESDIR}/pkg-message.in ${PKGMESSAGE}
.if defined(WITH_MOZILLA_PLUGIN)
	@${ECHO} "" >> ${PKGMESSAGE}
	@${CAT} ${FILESDIR}/pkg-message-mozilla.in >> ${PKGMESSAGE}
.endif
	@${REINPLACE_CMD} -e 's|/plugins||; \
		s|@MOZILLA_PLUGINDIR@|${PREFIX}/lib/browser_plugins|' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's|/dev/cdrom|${DEFAULT_CDROM_DEVICE}|' \
		${WRKSRC}/src/totem-preferences.c \
		${WRKSRC}/src/backend/bacon-video-widget-gst.c
.if defined(WITH_GSTREAMER)
	@${REINPLACE_CMD} -e 's|/dev/dvd|${DEFAULT_DVD_DEVICE}|' \
		${WRKSRC}/src/backend/bacon-video-widget-gst.c
.endif

post-install:
	@-update-desktop-database

.include <bsd.port.post.mk>
