# New ports collection makefile for:	gtk-xfce-engine
# Date Created:				10 October 2002
# Whom:				 	olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gtk-xfce-engine
PORTVERSION=	2.6.0
PORTREVISION=	1
CATEGORIES=	x11-themes xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
DIST_SUBDIR=	xfce4

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	An XFCE engine for GTK 2.0

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GNOME=	glib20 gnomehack gtk20 pkgconfig
USE_XFCE=	configenv	# to get MASTER_SITE_SUBDIR something has to be defined

.include <bsd.port.mk>
