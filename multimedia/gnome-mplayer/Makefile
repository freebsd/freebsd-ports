# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	gnome-mplayer
PORTVERSION=	1.0.9
PORTREVISION=	1
CATEGORIES=	multimedia gnome
MASTER_SITES=	https://launchpad.net/ubuntu/+archive/primary/+files/
DISTNAME=	gnome-mplayer_1.0.9.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNOME frontend for MPlayer

LICENSE=	GPLv2

LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
		libgmtk.so:multimedia/gmtk
RUN_DEPENDS=	mplayer:multimedia/mplayer

USES=		desktop-file-utils gettext gmake pkgconfig
USE_XORG=	x11 xscrnsaver
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-nautilus \
		--disable-nemo \
		--disable-schemas-install \
		--without-libgda
INSTALLS_ICONS=	yes
WRKSRC=		${WRKDIR}/gnome-mplayer-${PORTVERSION}

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lintl

GLIB_SCHEMAS=	apps.gecko-mediaplayer.preferences.gschema.xml \
		apps.gnome-mplayer.preferences.enums.xml \
		apps.gnome-mplayer.preferences.gschema.xml

OPTIONS_DEFINE=		ALSA BRAINZ3 DOCS GIO GPOD GTK3 NOTIFY PULSEAUDIO

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_RUN_DEPENDS=	alsa-plugins>0:audio/alsa-plugins
ALSA_CONFIGURE_WITH=	alsa
BRAINZ3_DESC=		Add support for libmusicbrainz
BRAINZ3_LIB_DEPENDS=	libmusicbrainz3.so:audio/libmusicbrainz3 \
			libcurl.so:ftp/curl
BRAINZ3_CONFIGURE_WITH=	libmusicbrainz3
GIO_DESC=		Use GIO for file I/O
GIO_CONFIGURE_WITH=	gio
GPOD_DESC=		Add support for libgpod
GPOD_LIB_DEPENDS=	libgpod.so:audio/libgpod
GPOD_CONFIGURE_WITH=	libgpod
GTK3_USE=		gnome=gtk30
GTK3_CONFIGURE_ENABLE=	gtk3
NOTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify
NOTIFY_RUN_DEPENDS=	notification-daemon>0:deskutils/notification-daemon
NOTIFY_CONFIGURE_WITH=	libnotify
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_WITH=	pulseaudio

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MGTK3}
USE_GNOME+=	gtk20
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/COPYING\\/d ; \
		 /INSTALL\\/d' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
