# New ports collection makefile for:	xfce-mcs-manager
# Date created:		7 June 2003
# Whom:			James Earl <jdearl@telus.net>
#
# $FreeBSD$
#

PORTNAME=	xfce4-mcs-manager
PORTVERSION=	4.4.1
CATEGORIES=	sysutils xfce
MASTER_SITES=	${MASTER_SITES_XFCE}
DISTNAME=	xfce-mcs-manager-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	XFce 4 settings manager

GNU_CONFIGURE=	yes
INSTALLS_ICONS= yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnometarget gtk20 intltool intlhack pkgconfig
USE_XFCE=	configenv libgui libmcs
USE_XLIB=	yes

.include <bsd.port.mk>
