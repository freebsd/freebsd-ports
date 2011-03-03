# New ports collection makefile for:	xfce4-smartbookmark-plugin
# Date created:				28 Januar 2007
# Whom:					Martin Wilke (miwi@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	xfce4-smartbookmark-plugin
PORTVERSION=	0.4.2
PORTREVISION=	16
CATEGORIES=	www xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=/src/panel-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A bookmark plugin for xfce panel.

USE_GMAKE=	yes
INSTALLS_ICONS=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnometarget gtk20 intltool intlhack pkgconfig
USE_XFCE=	configenv libgui libutil panel
USE_XORG=	x11 xt xaw

.include <bsd.port.mk>
