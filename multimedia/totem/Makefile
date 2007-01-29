# New ports collection makefile for:    totem
# Date created:         17 Oct 2002
# Whom:                 Hendrik Scholz <hendrik@scholz.net>
#
# $FreeBSD$
#

PORTNAME=	totem
PORTVERSION=	2.16.5
PORTREVISION?=	0
CATEGORIES=	multimedia gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER?=	gnome@FreeBSD.org
COMMENT?=	A Xine-based video player for the GNOME 2 Desktop

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

OPTIONS?=	DVDNAV "Enable DVD support" on \
		GSTREAMER "Use Gstreamer instead of Xine" off \
		MOZILLA_PLUGIN "Totem mozilla plugin" off

MAN1=	totem.1 totem-video-thumbnailer.1
GCONF_SCHEMAS=	totem-handlers.schemas totem-video-thumbnail.schemas \
		totem.schemas
CONFLICTS?=	totem-gstreamer-[0-9]*

.include <bsd.port.pre.mk>

.if defined(WITH_MOZILLA_PLUGIN)
USE_GECKO=	firefox mozilla seamonkey xulrunner<->firefox firefox15<->firefox
.include "${PORTSDIR}/www/mozilla/bsd.gecko.mk"
PLIST_SUB+=	MOZILLA=""
CONFIGURE_ARGS+=--with-mozilla=${GECKO} \
		--enable-gmp-plugin \
		--enable-complex-plugin \
		--enable-narrowspace-plugin
.else
PLIST_SUB+=	MOZILLA="@comment "
CONFIGURE_ARGS+=--without-mozilla \
		--disable-browser-plugins \
		--disable-mozilla \
		--disable-basic-plugin \
		--disable-gmp-plugin \
		--disable-complex-plugin \
		--disable-narrowspace-plugin
.endif

.if defined(WITH_GSTREAMER)
CONFIGURE_ARGS+=--enable-gstreamer=yes
USE_GSTREAMER+=	gnomevfs core gconf hal good mpeg2dec ugly
WITHOUT_DVDNAV=	yes
PLIST_SUB+=	GSTREAMER=""
.else
LIB_DEPENDS+=	xine.16:${PORTSDIR}/multimedia/libxine
PLIST_SUB+=	GSTREAMER="@comment "
.endif

.if defined(WITH_DVDNAV) && !defined(WITHOUT_DVDNAV)
LIB_DEPENDS+=	dvdnav.4:${PORTSDIR}/multimedia/libdvdnav
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
	@${ECHO_MSG} "===> The default DVD device is ${DEFAULT_DVD_DEVICE}"
	@${ECHO_MSG} "===> Define WITH_DVD_DEVICE if you want to change the default"
	@${ECHO_MSG} "===> For example, 'make WITH_DVD_DEVICE=\"/dev/somedevice\"'"

post-patch:
	@${CP} -f ${FILESDIR}/pkg-message.in ${PKGMESSAGE}
	@${REINPLACE_CMD} -e ' s|@MOZILLA_PLUGINDIR@|${PREFIX}/lib/browser_plugins|; \
		s|mozilla/plugins|browser_plugins|' \
		${WRKSRC}/browser-plugin/Makefile.in \
		${WRKSRC}/browser-plugin/idl/Makefile.in
.if defined(WITH_GSTREAMER)
	@${REINPLACE_CMD} -e 's|/dev/dvd|${DEFAULT_DVD_DEVICE}|' \
		${WRKSRC}/src/backend/bacon-video-widget-gst-0.10.c
.endif

post-install:
	@-update-desktop-database

.include <bsd.port.post.mk>
