# New ports collection makefile for:	xfce4-power-manager
# Date created:		2009-06-20
# Whom:			J.R. Oldroyd <fbsd@opal.com>
#
# $FreeBSD$
#

PORTNAME=	xfce4-power-manager
PORTVERSION=	0.8.0
CATEGORIES=	sysutils xfce
MASTER_SITES=	http://goodies.xfce.org/releases/${PORTNAME}/
DIST_SUBDIR=	xfce4

MAINTAINER=	fbsd@opal.com
COMMENT=	XFce4 power manager

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget gtk20 intltool intlhack pkgconfig

USE_XFCE=	configenv panel

MAN1=		xfce4-power-manager.1 xfce4-power-manager-settings.1

.include <bsd.port.mk>
