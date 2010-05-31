# New ports collection makefile for:	messenger plugin for xfce4
# Date created:				29 April 2006
# Whom:					Martin Wilke (freebsd@unixfreunde.de)
#
# $FreeBSD$
#

PORTNAME=	xfce4-messenger-plugin
PORTVERSION=	0.1.0
PORTREVISION=	13
CATEGORIES=	net-im xfce
MASTER_SITES=	ftp://ftp.berlios.de/pub/xfce-goodies/panel-plugins/4.4/
DIST_SUBDIR=	xfce4

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Messenger plugin for xfce

LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget gtk20 intltool intlhack pkgconfig
USE_XFCE=	configenv libgui libutil panel
USE_XORG=	x11 xt xaw

.include <bsd.port.mk>
