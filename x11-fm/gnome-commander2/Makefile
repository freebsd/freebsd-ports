# New ports collection makefile for:	gnomem-commander
# Date created:		23 April 2002
# Whom:			Edgardo Garcia Hoeffler <edybsd@yahoo.com.ar>
#
# $FreeBSD$
#

PORTNAME=	gnome-commander
PORTVERSION=	1.1.6
PORTREVISION=	2
CATEGORIES=	x11-fm gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-commander/1.1
PKGNAMESUFFIX=	2
DIST_SUBDIR=	gnome2

MAINTAINER=	rehsack@liwing.de
COMMENT=	File manager for Gnome2

CONFLICTS=	gnome-commander-*

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomeprefix gnomehack gnometarget libgnomeui lthack
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib -lintl"

.include <bsd.port.mk>
