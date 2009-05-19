# New ports collection makefile for:	vino
# Date created:				16 July 2004
# Whom:					Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#   $MCom: ports-stable/net/vino/Makefile,v 1.1 2009/04/15 09:28:05 kwm Exp $
#

PORTNAME=	vino
PORTVERSION=	2.26.2
CATEGORIES=	net gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	VNC server that allows for remote access to your GNOME desktop

LIB_DEPENDS=	gnutls:${PORTSDIR}/security/gnutls \
    		unique-1.0.2:${PORTSDIR}/x11-toolkits/unique

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack gnomepanel
USE_XORG=	xtst
USE_GMAKE=	yes
GNOME_DESKTOP_VERSION=2
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	vino-server.schemas

.if !defined(WITHOUT_NOTIFY)
LIB_DEPENDS+=	notify.1:${PORTSDIR}/devel/libnotify
CONFIGURE_ARGS+=--enable-libnotify=yes
.else
CONFIGURE_ARGS+=--enable-libnotify=no
.endif

.include <bsd.port.mk>
