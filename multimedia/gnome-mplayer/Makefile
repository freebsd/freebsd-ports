# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	gnome-mplayer
PORTVERSION=	1.0.8
PORTREVISION=	1
CATEGORIES=	multimedia gnome
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNOME frontend for MPlayer

LICENSE=	GPLv2

LIB_DEPENDS=	dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		gmtk:${PORTSDIR}/multimedia/gmtk
RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer

OPTIONS_DEFINE=	ALSA BRAINZ3 DOCS GIO GPOD GTK3 NAUPLUG NLS NOTIFY PULSEAUDIO
BRAINZ3_DESC=	Add support for libmusicbrainz
GIO_DESC=	Use GIO for file I/O
GPOD_DESC=	Add support for libgpod
NAUPLUG_DESC=	Enable Nautilus plugin

USES=		gmake
GNU_CONFIGURE=	yes
USE_GNOME=	glib20
USE_XORG=	x11 xscrnsaver
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		${PORTNAME}.1
PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README \
		dbus.txt keyboard_shortcuts.txt plugin-interaction.txt

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MALSA}
LIB_DEPENDS+=	asound:${PORTSDIR}/audio/alsa-lib
RUN_DEPENDS+=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:${PORTSDIR}/audio/alsa-plugins
CONFIGURE_ARGS+=	--with-alsa
.else
CONFIGURE_ARGS+=	--without-alsa
.endif

.if ${PORT_OPTIONS:MBRAINZ3}
LIB_DEPENDS+=	musicbrainz3:${PORTSDIR}/audio/libmusicbrainz3 \
		curl:${PORTSDIR}/ftp/curl
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
LIB_DEPENDS+=	gpod:${PORTSDIR}/audio/libgpod
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

.if ${PORT_OPTIONS:MNAUPLUG}
USE_GNOME+=	nautilus2
PLIST_SUB+=	PLUGIN=""
CONFIGURE_ARGS+=	--enable-nautilus
.else
PLIST_SUB+=	PLUGIN="@comment "
CONFIGURE_ARGS+=	--enable-nautilus=no
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB+=	NLS=""
LDFLAGS+=	-lintl
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MNOTIFY}
LIB_DEPENDS+=	notify:${PORTSDIR}/devel/libnotify
RUN_DEPENDS+=	${LOCALBASE}/libexec/notification-daemon:${PORTSDIR}/deskutils/notification-daemon
CONFIGURE_ARGS+=	--with-libnotify
.else
CONFIGURE_ARGS+=	--without-libnotify
.endif

.if ${PORT_OPTIONS:MPULSEAUDIO}
LIB_DEPENDS+=	pulse:${PORTSDIR}/audio/pulseaudio
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
