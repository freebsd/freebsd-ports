# New ports collection makefile for:   gnomenetwork
# Date Created:			03 June 2003
# Whom:				Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomenettool
PORTVERSION=	0.99.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-nettool/0.99
DISTNAME=	gnome-nettool-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A GNOME utility that provides network information statistics

USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack intlhack gnomeprefix libgnomeui
USE_GMAKE=	yes
USE_LIBTOOL_VER=15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-install:
	${MKDIR} ${PREFIX}/share/gnome/pixmaps
	${LN} -sf ${PREFIX}/share/gnome/gnome-nettool/pixmaps/gnome-nettool.png \
		${PREFIX}/share/gnome/pixmaps/gnome-nettool.png

.include <bsd.port.mk>
