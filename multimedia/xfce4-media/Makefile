# Created by: Matt Lancereau <ports@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xfce4-media
PORTVERSION=	0.9.2
PORTREVISION=	28
CATEGORIES=	multimedia xfce
MASTER_SITES=	http://spuriousinterrupt.org/files/xfmedia/
DISTNAME=	xfmedia-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Lightweight media player for Xfce4 based on the xine engine

LIB_DEPENDS=	xine:${PORTSDIR}/multimedia/libxine

DEPRECATED=	Upstream development dead, use multimedia/xfce4-parole instead
EXPIRATION_DATE=	2014-01-04 

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USES=		pathfix pkgconfig gettext
USE_GNOME=	glib20 gtk20 intltool intlhack
USE_XFCE=	configenv libexo libgui libutil panel
USE_XORG=	x11 sm

OPTIONS_DEFINE=	TAGLIB DBUS STARTUP
OPTIONS_DEFAULT=	DBUS STARTUP

TAGLIB_DESC=	metadata editing support
STARTUP_DESC=	startup notification support

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MTABLIB}
LIB_DEPENDS+=	tag:${PORTSDIR}/audio/taglib
CONFIGURE_ARGS+=--with-taglib
.else
CONFIGURE_ARGS+=--without-taglib
.endif

.if ${PORT_OPTIONS:MDBUS}
LIB_DEPENDS+=	dbus-glib-1:${PORTSDIR}/devel/dbus-glib
CONFIGURE_ARGS+=--enable-dbus
.else
CONFIGURE_ARGS+=--disable-dbus
.endif

.if ${PORT_OPTIONS:MSTARTUP}
LIB_DEPENDS+=	startup-notification-1:${PORTSDIR}/x11/startup-notification
CONFIGURE_ARGS+=--enable-startup-notification
.else
CONFIGURE_ARGS+=--disable-startup-notification
.endif

CFLAGS+=	-I${LOCALBASE}/include

post-patch:
	@${REINPLACE_CMD} -e "s|xfmedia_remote_LDADD = |&@LIBXFCEGUI4_LIBS@|" \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e "s|exo-0.3|exo-1|" ${WRKSRC}/configure
.for file in mediamarks.c playlist.c settings-dialog.c xfmedia-playlist-queue.c
	@${REINPLACE_CMD} -e "s|EXO_PANGO_ELLIPSIZE_END|PANGO_ELLIPSIZE_END|" \
		${WRKSRC}/src/${file}
.endfor

.include <bsd.port.post.mk>
