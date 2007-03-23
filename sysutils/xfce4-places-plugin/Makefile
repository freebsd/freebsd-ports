# New ports collection makefile for:	xfce4-places-plugin
# Date created:		2007-03-23
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xfce4-places-plugin
PORTVERSION=	0.0.9
CATEGORIES=	sysutils xfce
MASTER_SITES=	http://goodies.xfce.org/releases/${PORTNAME}/
DIST_SUBDIR=	xfce4

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A file browser launcher for XFce4 panel plugin

GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget gtk20 intltool intlhack pkgconfig
USE_XFCE=	configenv panel
USE_XLIB=	yes

.include <bsd.port.mk>
