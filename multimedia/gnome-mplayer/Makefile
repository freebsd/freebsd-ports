# New ports collection makefile for:	gnome-mplayer
# Date created:				21 February 2009
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$
#

PORTNAME=	gnome-mplayer
PORTVERSION=	0.9.5
PORTREVISION=	2
CATEGORIES=	multimedia gnome
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	avl@FreeBSD.org
COMMENT=	GNOME frontend for MPlayer

LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer

OPTIONS=	GIO	"Use GIO for file I/O"			off \
		GCONF	"Use Gconf to store preferences"	off \
		NOTIFY	"Send notifications of new media"	off \
		GPOD	"Add support for libgpod"		off \
		BRAINZ3	"Add support for libmusicbrainz3"	off \
		NAUPLUG	"Enable Nautilus plugin"		off

MAKE_JOBS_SAFE=	yes

GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_GNOME=	glib20 gtk20
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=	--without-alsa

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README \
		dbus.txt keyboard_shortcuts.txt plugin-interaction.txt

.include <bsd.port.pre.mk>

.if defined(WITH_GIO)
CONFIGURE_ARGS+=	--with-gio
.else
CONFIGURE_ARGS+=	--without-gio
.endif

.if defined(WITH_GCONF)
USE_GNOME+=	gconf2
CONFIGURE_ARGS+=	--with-gconf
GCONF_SCHEMAS=	${PORTNAME}.schemas
.else
CONFIGURE_ARGS+=	--without-gconf --disable-schemas-install
.endif

.if defined(WITH_NOTIFY)
LIB_DEPENDS+=	notify.1:${PORTSDIR}/devel/libnotify
RUN_DEPENDS+=	${LOCALBASE}/libexec/notification-daemon:${PORTSDIR}/deskutils/notification-daemon
CONFIGURE_ARGS+=	--with-libnotify
.else
CONFIGURE_ARGS+=	--without-libnotify
.endif

.if defined(WITH_GPOD)
LIB_DEPENDS+=	gpod.5:${PORTSDIR}/audio/libgpod
CONFIGURE_ARGS+=	--with-libgpod
.else
CONFIGURE_ARGS+=	--without-libgpod
.endif

.if defined(WITH_BRAINZ3)
LIB_DEPENDS+=	musicbrainz3.6:${PORTSDIR}/audio/libmusicbrainz3
CONFIGURE_ARGS+=	--with-libmusicbrainz3
.else
CONFIGURE_ARGS+=	--without-libmusicbrainz3
.endif

.if defined(WITH_NAUPLUG)
USE_GNOME+=	nautilus2
PLIST_SUB+=	PLUGIN=""
CONFIGURE_ARGS+=	--enable-nautilus
.else
PLIST_SUB+=	PLUGIN="@comment "
CONFIGURE_ARGS+=	--enable-nautilus=no
.endif

post-patch:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e \
		's/install-desktopDATA install-gnome_mplayerdocDATA/install-desktopDATA/' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.post.mk>
