# New ports collection makefile for:	datetimer plugin for xfce4
# Date created:				02 February 2007
# Whom:					Martin Wilke (miwi@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	xfce4-datetime-plugin
PORTVERSION=	0.6.1
PORTREVISION=	8
CATEGORIES=	x11-clocks xfce
MASTER_SITES=	http://goodies.xfce.org/releases/${PORTNAME}/
DIST_SUBDIR=	xfce4

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A datetime plugin for xfce

USE_GMAKE=	yes
USE_BZIP2=	yes
INSTALLS_ICONS=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnometarget gtk20 intltool intlhack pkgconfig
USE_XFCE=	configenv libgui libutil panel

.include <bsd.port.mk>
