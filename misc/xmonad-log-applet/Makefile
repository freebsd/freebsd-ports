# New ports collection makefile for:	xmonad-log-applet
# Date created:				01 September 2011
# Whom:					Alexander Kojevnikov <alexander@kojevnikov.com>
#
# $FreeBSD$
#

PORTNAME=	xmonad-log-applet
PORTVERSION=	2.0.0
CATEGORIES=	misc
MASTER_SITES=	http://cloud.github.com/downloads/alexkay/${PORTNAME}/

MAINTAINER=	alexander@kojevnikov.com
COMMENT=	An applet that will display Xmonad log information

INSTALLS_ICONS=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomepanel
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-panel=gnome2

.include <bsd.port.mk>
