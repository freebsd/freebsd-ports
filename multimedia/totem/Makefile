# New ports collection makefile for:    totem
# Date created:         17 Oct 2002
# Whom:                 Hendrik Scholz <hendrik@scholz.net>
#
# $FreeBSD$
#

PORTNAME=	totem
PORTVERSION=	0.99.13
CATEGORIES=	multimedia gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/...$//}
DIST_SUBDIR=	gnome2

MAINTAINER=	hendrik@scholz.net
COMMENT=	A Xine-based video player for the Gnome 2 Desktop

USE_REINPLACE=	yes
USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack gnomedesktop
USE_GMAKE=	yes
USE_LIBTOOL_VER=13
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
	       	LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib -lXrandr"

OPTIONS=	GSTREAMER_OVERRIDE "Use GStreamer instead of xine" off \
		DVDNAV "Enable DVD support" on

MAN1=	totem.1

.include <bsd.port.pre.mk>

.if defined(WITH_GSTREAMER_OVERRIDE)
CONFIGURE_ARGS+=--enable-gstreamer
USE_GNOME+=	gstreamerplugins
WITHOUT_DVDNAV=	yes
.else
LIB_DEPENDS+=	xine.9:${PORTSDIR}/multimedia/libxine
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

.if defined(WITH_GSTREAMER_OVERRIDE)
.if defined(WITH_DVD_DEVICE)
DEFAULT_DVD_DEVICE=${WITH_DVD_DEVICE}
.else
.if ${OSVERSION} < 500000
DEFAULT_DVD_DEVICE=/dev/acd0c
.else
DEFAULT_DVD_DEVICE=/dev/acd0
.endif
.endif
.endif

pre-everything::
	@${ECHO_MSG} "===> The default CDROM device is ${DEFAULT_CDROM_DEVICE}"
	@${ECHO_MSG} "===> Define WITH_CDROM_DEVICE if you want to change the default"
	@${ECHO_MSG} "===> For example, 'make WITH_CDROM_DEVICE=\"/dev/somedevice\"'"
	@${ECHO_MSG} "===>"
.if defined(WITH_GSTREAMER_OVERRIDE)
	@${ECHO_MSG} "===> The default DVD device is ${DEFAULT_DVD_DEVICE}"
	@${ECHO_MSG} "===> Define WITH_DVD_DEVICE if you want to change the default"
	@${ECHO_MSG} "===> For example, 'make WITH_DVD_DEVICE=\"/dev/somedevice\"'"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/dev/cdrom|${DEFAULT_CDROM_DEVICE}|' \
		${WRKSRC}/src/cd-drive.c \
		${WRKSRC}/src/totem-preferences.c \
		${WRKSRC}/src/bacon-cd-selection.c
.if defined(WITH_GSTREAMER_OVERRIDE)
	@${REINPLACE_CMD} -e 's|/dev/dvd|${DEFAULT_DVD_DEVICE}|' \
		${WRKSRC}/src/bacon-video-widget-gst.c
.endif

.include <bsd.port.post.mk>
