# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	gnome-mplayer
PORTVERSION=	1.0.0
PORTREVISION=	3
CATEGORIES=	multimedia gnome
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNOME frontend for MPlayer

LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer

OPTIONS_DEFINE=	GIO GCONF NOTIFY GPOD BRAINZ3 NAUPLUG PANSCAN DOCS
GIO_DESC=	Use GIO for file I/O
GPOD_DESC=	Add support for libgpod
BRAINZ3_DESC=	Add support for libmusicbrainz
NAUPLUG_DESC=	Enable Nautilus plugin
PANSCAN_DESC=	Enable panscan functionality

MAKE_JOBS_SAFE=	yes

GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_GNOME=	glib20 gtk20
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	--without-alsa

MAN1=		${PORTNAME}.1
PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README \
		dbus.txt keyboard_shortcuts.txt plugin-interaction.txt

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGIO}
CONFIGURE_ARGS+=	--with-gio
.else
CONFIGURE_ARGS+=	--without-gio
.endif

.if ${PORT_OPTIONS:MGCONF}
USE_GNOME+=	gconf2
CONFIGURE_ARGS+=	--with-gconf
GCONF_SCHEMAS=	${PORTNAME}.schemas
.else
CONFIGURE_ARGS+=	--without-gconf --disable-schemas-install
.endif

.if ${PORT_OPTIONS:MNOTIFY}
LIB_DEPENDS+=	notify.4:${PORTSDIR}/devel/libnotify
RUN_DEPENDS+=	${LOCALBASE}/libexec/notification-daemon:${PORTSDIR}/deskutils/notification-daemon
CONFIGURE_ARGS+=	--with-libnotify
.else
CONFIGURE_ARGS+=	--without-libnotify
.endif

.if ${PORT_OPTIONS:MGPOD}
LIB_DEPENDS+=	gpod.7:${PORTSDIR}/audio/libgpod
CONFIGURE_ARGS+=	--with-libgpod
.else
CONFIGURE_ARGS+=	--without-libgpod
.endif

.if ${PORT_OPTIONS:MBRAINZ3}
LIB_DEPENDS+=	musicbrainz3.6:${PORTSDIR}/audio/libmusicbrainz3 \
		curl.6:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=	--with-libmusicbrainz3
.else
CONFIGURE_ARGS+=	--without-libmusicbrainz3
.endif

.if ${PORT_OPTIONS:MNAUPLUG}
USE_GNOME+=	nautilus2
PLIST_SUB+=	PLUGIN=""
CONFIGURE_ARGS+=	--enable-nautilus
.else
PLIST_SUB+=	PLUGIN="@comment "
CONFIGURE_ARGS+=	--enable-nautilus=no
.endif

.if ${PORT_OPTIONS:MPANSCAN}
CONFIGURE_ARGS+=	--enable-panscan
.else
CONFIGURE_ARGS+=	--enable-panscan=no
.endif

post-patch:
.if ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e \
		's/install-desktopDATA install-gnome_mplayerdocDATA/install-desktopDATA/' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
