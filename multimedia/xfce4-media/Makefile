# New ports collection makefile for:	Xfce4-media
# Date created:		23 October 2004
# Whom:			Matt Lancereau <ports@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xfce4-media
PORTVERSION=	0.9.2
PORTREVISION=	19
CATEGORIES=	multimedia xfce
MASTER_SITES=	http://spuriousinterrupt.org/files/xfmedia/
DISTNAME=	xfmedia-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight media player for Xfce4 based on the xine engine

LIB_DEPENDS=	xine.1:${PORTSDIR}/multimedia/libxine

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20 gnomehack gnometarget gtk20 intltool intlhack pkgconfig
USE_XFCE=	configenv libexo libgui libutil panel
USE_XORG=	x11 sm

OPTIONS=	TAGLIB	"Enable metadata editing"		off \
		DBUS	"Enable D-BUS support"			on \
		STARTUP "Enable startup notification support"	on

.include <bsd.port.pre.mk>

.if defined(WITH_TAGLIB)
LIB_DEPENDS+=	tag.1:${PORTSDIR}/audio/taglib
CONFIGURE_ARGS+=--with-taglib
.else
CONFIGURE_ARGS+=--without-taglib
.endif

.if !defined(WITHOUT_DBUS)
LIB_DEPENDS+=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
CONFIGURE_ARGS+=--enable-dbus
.else
CONFIGURE_ARGS+=--disable-dbus
.endif

.if !defined(WITHOUT_STARTUP)
LIB_DEPENDS+=	startup-notification-1.0:${PORTSDIR}/x11/startup-notification
CONFIGURE_ARGS+=--enable-startup-notification
.else
CONFIGURE_ARGS+=--disable-startup-notification
.endif

CFLAGS+=	-I${LOCALBASE}/include

post-patch:
	@${REINPLACE_CMD} -e "s|xfmedia_remote_LDADD = |&@LIBXFCEGUI4_LIBS@|" \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.post.mk>
