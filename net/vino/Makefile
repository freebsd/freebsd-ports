# Created by: Tom McLaughlin <tmclaugh@sdf.lonestar.org>
# $FreeBSD$
#   $MCom: ports/net/vino/Makefile,v 1.81 2010/09/27 13:51:24 kwm Exp $

PORTNAME=	vino
PORTVERSION=	2.32.2
PORTREVISION=	4
CATEGORIES=	net gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	VNC server that allows for remote access to your GNOME desktop

LIB_DEPENDS=	gnutls:${PORTSDIR}/security/gnutls \
		telepathy-glib.0:${PORTSDIR}/net-im/telepathy-glib \
		unique-1.0.2:${PORTSDIR}/x11-toolkits/unique

USE_BZIP2=	yes
USES=		gettext gmake pkgconfig
USE_GNOME=	gnomeprefix intlhack gnomehack gnomepanel
USE_XORG=	xtst
GNOME_DESKTOP_VERSION=2
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	vino-server.schemas

.if !defined(WITHOUT_NOTIFY)
LIB_DEPENDS+=	notify.4:${PORTSDIR}/devel/libnotify
CONFIGURE_ARGS+=--enable-libnotify=yes
.else
CONFIGURE_ARGS+=--enable-libnotify=no
.endif

NO_STAGE=	yes
.include <bsd.port.mk>
