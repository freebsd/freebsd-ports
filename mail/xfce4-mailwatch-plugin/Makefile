# New ports collection makefile for:	mailwatch plugin for xfce4
# Date created:				23 Januar 2007
# Whom:					Martin Wilke (miwi@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	xfce4-mailwatch-plugin
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	mail xfce
MASTER_SITES=	http://spuriousinterrupt.org/files/mailwatch/ \
		http://freebsd.unixfreunde.de/sources/
DIST_SUBDIR=	xfce4

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A mailwatch plugin for xfce

USE_BZIP2=	yes
USE_GMAKE=	yes
INSTALLS_ICONS=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnometarget gtk20 intltool intlhack pkgconfig
USE_XFCE=	configenv libgui libutil panel
USE_XLIB=	yes

.include <bsd.port.mk>
