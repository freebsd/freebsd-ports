# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	gnome-mplayer
PORTVERSION=	1.0.8
PORTREVISION=	2
CATEGORIES=	multimedia gnome
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNOME frontend for MPlayer

LICENSE=	GPLv2

LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libgmtk.so:${PORTSDIR}/multimedia/gmtk
RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer

OPTIONS_DEFINE=	ALSA BRAINZ3 DOCS GIO GPOD GTK3 NLS NOTIFY PULSEAUDIO
BRAINZ3_DESC=	Add support for libmusicbrainz
GIO_DESC=	Use GIO for file I/O
GPOD_DESC=	Add support for libgpod

USES=		desktop-file-utils gettext gmake pkgconfig
GNU_CONFIGURE=	yes
USE_GNOME=	glib20
USE_XORG=	x11 xscrnsaver
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	LIBS='-lintl'
CONFIGURE_ARGS=	--disable-nautilus

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README \
		dbus.txt keyboard_shortcuts.txt plugin-interaction.txt

GLIB_SCHEMAS=	apps.gecko-mediaplayer.preferences.gschema.xml \
		apps.gnome-mplayer.preferences.enums.xml \
		apps.gnome-mplayer.preferences.gschema.xml

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MALSA}
LIB_DEPENDS+=	libasound.so:${PORTSDIR}/audio/alsa-lib
RUN_DEPENDS+=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:${PORTSDIR}/audio/alsa-plugins
CONFIGURE_ARGS+=	--with-alsa
.else
CONFIGURE_ARGS+=	--without-alsa
.endif

.if ${PORT_OPTIONS:MBRAINZ3}
LIB_DEPENDS+=	libmusicbrainz3.so:${PORTSDIR}/audio/libmusicbrainz3 \
		libcurl.so:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=	--with-libmusicbrainz3
.else
CONFIGURE_ARGS+=	--without-libmusicbrainz3
.endif

.if ${PORT_OPTIONS:MGIO}
CONFIGURE_ARGS+=	--with-gio
.else
CONFIGURE_ARGS+=	--without-gio
.endif

.if ${PORT_OPTIONS:MGPOD}
LIB_DEPENDS+=	libgpod.so:${PORTSDIR}/audio/libgpod
CONFIGURE_ARGS+=	--with-libgpod
.else
CONFIGURE_ARGS+=	--without-libgpod
.endif

.if ${PORT_OPTIONS:MGTK3}
USE_GNOME+=	gtk30
CONFIGURE_ARGS+=	--enable-gtk3
.else
USE_GNOME+=	gtk20
CONFIGURE_ARGS+=	--disable-gtk3
.endif

.if ${PORT_OPTIONS:MNOTIFY}
LIB_DEPENDS+=	libnotify.so:${PORTSDIR}/devel/libnotify
RUN_DEPENDS+=	${LOCALBASE}/libexec/notification-daemon:${PORTSDIR}/deskutils/notification-daemon
CONFIGURE_ARGS+=	--with-libnotify
.else
CONFIGURE_ARGS+=	--without-libnotify
.endif

.if ${PORT_OPTIONS:MPULSEAUDIO}
LIB_DEPENDS+=	libpulse.so:${PORTSDIR}/audio/pulseaudio
CONFIGURE_ARGS+=	--with-pulseaudio
.else
CONFIGURE_ARGS+=	--without-pulseaudio
.endif

post-patch:
.if empty(PORT_OPTIONS:MDOCS)
	@${REINPLACE_CMD} -e \
		's/install-desktopDATA install-gnome_mplayerdocDATA/install-desktopDATA/' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
