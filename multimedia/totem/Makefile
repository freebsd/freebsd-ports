# New ports collection makefile for:    totem
# Date created:         17 Oct 2002
# Whom:                 Hendrik Scholz <hendrik@scholz.net>
#
# $FreeBSD$
#

PORTNAME=	totem
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	multimedia gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER?=	hendrik@scholz.net
COMMENT?=	A Xine-based video player for the Gnome 2 Desktop

USE_REINPLACE=	yes
USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack gnomedesktop desktopfileutils \
		nautiluscdburner
WANT_GSTREAMER=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes
INSTALLS_OMF=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
	       	LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib -lXrandr"
CONFIGURE_ARGS+=--disable-mozilla

OPTIONS?=	DVDNAV "Enable DVD support" on \
		GSTREAMER "Use Gstreamer instead of Xine" off

MAN1=	totem.1
GCONF_SCHEMAS=	totem-handlers.schemas totem-video-thumbnail.schemas \
		totem.schemas
CONFLICTS=	totem-gstreamer-[0-9]*

.include <bsd.port.pre.mk>

.if defined(WITH_GSTREAMER)
CONFIGURE_ARGS+=--enable-gstreamer
USE_GSTREAMER+=	gnomevfs core gconf
WITHOUT_DVDNAV=	yes
PLIST_SUB=	GSTREAMER=""
.else
LIB_DEPENDS+=	xine.12:${PORTSDIR}/multimedia/libxine
PLIST_SUB=	GSTREAMER="@comment "
.endif

.if defined(WITH_DVDNAV) && !defined(WITHOUT_DVDNAV)
LIB_DEPENDS+=	dvdnav.3:${PORTSDIR}/multimedia/libdvdnav
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
	@${REINPLACE_CMD} -e 's|/dev/cdrom|${DEFAULT_CDROM_DEVICE}|' \
		${WRKSRC}/src/totem-preferences.c \
		${WRKSRC}/src/bacon-video-widget-gst.c
.if defined(WITH_GSTREAMER)
	@${REINPLACE_CMD} -e 's|/dev/dvd|${DEFAULT_DVD_DEVICE}|' \
		${WRKSRC}/src/bacon-video-widget-gst.c
.endif
	@${REINPLACE_CMD} -e 's|@LOCALBASE@|${LOCALBASE}|' \
		${WRKSRC}/src/bacon-video-widget-xine.c

post-install:
	@-update-desktop-database

.include <bsd.port.post.mk>
