# New ports collection makefile for:    totem
# Date created:         17 Oct 2002
# Whom:                 Hendrik Scholz <hendrik@scholz.net>
#
# $FreeBSD$
#    $MCom: ports/multimedia/totem/Makefile,v 1.77 2007/03/11 05:25:07 mezz Exp $
#

PORTNAME=	totem
PORTVERSION=	2.18.2
PORTREVISION?=	0
CATEGORIES=	multimedia gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER?=	gnome@FreeBSD.org
COMMENT?=	A gstreamer-based video player for the GNOME 2 Desktop

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes
LIB_DEPENDS=	musicbrainz:${PORTSDIR}/audio/libmusicbrainz \
		hal.1:${PORTSDIR}/sysutils/hal
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_XLIB=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack gnomedesktop desktopfileutils \
		nautiluscdburner ltverhack
GNOME_DESKTOP_VERSION=2
WANT_GSTREAMER=	yes
INSTALLS_ICONS=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
USE_LDCONFIG=	yes
INSTALLS_OMF=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
	       	LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib -lXrandr"

MAN1=		totem.1 totem-video-thumbnailer.1
GCONF_SCHEMAS=	totem-handlers.schemas totem-video-thumbnail.schemas \
		totem.schemas
CONFLICTS?=	totem-gstreamer-[0-9]* totem-xine-[0-9]*

.include <bsd.port.pre.mk>

.if defined(WITH_MOZILLA_PLUGIN) && ${SLAVE_PORT:L}=="yes"
USE_GECKO=	firefox mozilla seamonkey xulrunner<->firefox firefox-devel<->firefox
.include "${PORTSDIR}/www/mozilla/bsd.gecko.mk"
CONFIGURE_ARGS+=--with-mozilla=${GECKO} \
		--enable-gmp-plugin \
		--enable-complex-plugin \
		--enable-narrowspace-plugin
BUILD_WRKSRC=	${WRKSRC}/browser-plugin
INSTALL_WRKSRC=	${WRKSRC}/browser-plugin
.else
CONFIGURE_ARGS+=--without-mozilla \
		--disable-browser-plugins \
		--disable-mozilla \
		--disable-basic-plugin \
		--disable-gmp-plugin \
		--disable-complex-plugin \
		--disable-narrowspace-plugin
.endif

.if !defined(WITH_TOTEM_XINE) || ${SLAVE_PORT}=="no"
CONFIGURE_ARGS+=--enable-gstreamer=yes
USE_GSTREAMER+=	gnomevfs core gconf hal good mpeg2dec ugly
WITHOUT_DVDNAV=	yes
PLIST_SUB+=	GSTREAMER=""
.else
CONFIGURE_ARGS+=--enable-xine=yes
LIB_DEPENDS+=	xine.1:${PORTSDIR}/multimedia/libxine
PLIST_SUB+=	GSTREAMER="@comment "

BROKEN=		needs libxine-1.1.7
.endif

.if defined(WITH_DVDNAV) && !defined(WITHOUT_DVDNAV)
LIB_DEPENDS+=	dvdnav.4:${PORTSDIR}/multimedia/libdvdnav
.endif

.if defined(WITH_DVD_DEVICE)
DEFAULT_DVD_DEVICE=${WITH_DVD_DEVICE}
.else
DEFAULT_DVD_DEVICE=/dev/acd0
.endif

pre-everything::
	@${ECHO_MSG} "===> The default DVD device is ${DEFAULT_DVD_DEVICE}"
	@${ECHO_MSG} "===> Define WITH_DVD_DEVICE if you want to change the default"
	@${ECHO_MSG} "===> For example, 'make WITH_DVD_DEVICE=\"/dev/somedevice\"'"

post-patch:
	@${CP} -f ${FILESDIR}/pkg-message.in ${PKGMESSAGE}
	@${REINPLACE_CMD} -e ' s|@MOZILLA_PLUGINDIR@|${PREFIX}/lib/browser_plugins|; \
		s|mozilla/plugins|browser_plugins|' \
		${WRKSRC}/browser-plugin/Makefile.in \
		${WRKSRC}/browser-plugin/idl/Makefile.in
	@${REINPLACE_CMD} -e 's|dbus >= 0.61|dbus-1 >= 0.61|g' \
	    	${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/dev/dvd|${DEFAULT_DVD_DEVICE}|' \
		${WRKSRC}/src/backend/bacon-video-widget-gst-0.10.c

post-install:
	@-update-desktop-database

.include <bsd.port.post.mk>
