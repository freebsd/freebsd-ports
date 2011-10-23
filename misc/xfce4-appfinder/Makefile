# New ports collection makefile for:	xfce4-appfinder
# Date created:				12 October 2004
# Whom:					Oliver Lehmann <oliver@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xfce4-appfinder
PORTVERSION=	4.8.0
PORTREVISION=	1
CATEGORIES=	misc xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Find application in the system supporting Desktop entry format

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20 intltool intlhack pkgconfig
USE_XFCE=	configenv garcon libgui libmenu libutil thunar xfconf

.include <bsd.port.mk>
