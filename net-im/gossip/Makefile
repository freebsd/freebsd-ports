# New ports collection makefile for:	gossip
# Date created:				08 July 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/net-im/gossip/Makefile,v 1.10 2007/07/30 20:30:21 mezz Exp $
#

PORTNAME=	gossip
PORTVERSION=	0.31
PORTREVISION=	5
CATEGORIES=	net-im gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GTK2 Jabber Instant Messaging client

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes
LIB_DEPENDS=	loudmouth-1.0:${PORTSDIR}/net-im/loudmouth \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		aspell.16:${PORTSDIR}/textproc/aspell
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes

USE_XORG=	x11 xext ice xscrnsaver
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack gnomepanel gnomedocutils \
		libgnomeui
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--enable-dbus=yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	gossip.schemas

OPTIONS=	NOTIFY "Enable libnotify support" on \
		TELEPATHY "Enable telepathy support" off \
		EBOOK "Enable Evolution integration" off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_NOTIFY)
LIB_DEPENDS+=		notify.1:${PORTSDIR}/devel/libnotify
.else
CONFIGURE_ARGS+=	--enable-libnotify=no
.endif

.if defined(WITH_TELEPATHY)
LIB_DEPENDS+=		telepathy.2:${PORTSDIR}/net-im/libtelepathy
CONFIGURE_ARGS+=	--enable-telepathy=yes
.else
CONFIGURE_ARGS+=	--enable-telepathy=no
.endif

.if defined(WITH_EBOOK)
USE_GNOME+=	evolutiondataserver
.else
CONFIGURE_ARGS+=	--enable-ebook=no
.endif

.include <bsd.port.post.mk>
