# New ports collection makefile for:	xfce4-fsguard-plugin
# Date created:		2003-12-20
# Whom:			Matt Lancereau <matt@rimasec.net>
#
# $FreeBSD$
#

PORTNAME=	xfce4-fsguard-plugin
PORTVERSION=	0.4.2
PORTREVISION=	8
CATEGORIES=	sysutils xfce
MASTER_SITES=	http://goodies.xfce.org/releases/${PORTNAME}/
DIST_SUBDIR=	xfce4

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	XFce4 panel plugin to check a mountpoint for free disk space

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget gtk20 intltool intlhack pkgconfig
USE_XFCE=	configenv panel

.include <bsd.port.mk>
