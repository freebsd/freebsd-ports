# New ports collection makefile for:	xfce4-cpugraph-plugin
# Date created:		2004-06-07
# Whom:			Matt Lancereau <matt@rimasec.net>
#
# $FreeBSD$
#

PORTNAME=	xfce4-cpugraph-plugin
PORTVERSION=	0.3.0
PORTREVISION=	9
CATEGORIES=	sysutils xfce
MASTER_SITES=	http://goodies.xfce.org/releases/${PORTNAME}/
DIST_SUBDIR=	xfce4

MAINTAINER=	fbsd@opal.com
COMMENT=	XFce4 systemload plugin with multiple CPU display modes

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget gtk20 intltool intlhack pkgconfig
USE_XFCE=	configenv panel

.include <bsd.port.mk>
