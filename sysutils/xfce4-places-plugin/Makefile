# New ports collection makefile for:	xfce4-places-plugin
# Date created:		2007-03-23
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xfce4-places-plugin
PORTVERSION=	1.1.0
PORTREVISION=	3
CATEGORIES=	sysutils xfce
MASTER_SITES=	http://goodies.xfce.org/releases/${PORTNAME}/
DIST_SUBDIR=	xfce4

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A file browser launcher for XFce4 panel plugin

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget gtk20 intltool intlhack pkgconfig
USE_XFCE=	configenv panel thunar

.include <bsd.port.mk>
