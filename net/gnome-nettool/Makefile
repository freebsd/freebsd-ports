# New ports collection makefile for:   gnomenetwork
# Date Created:			03 June 2003
# Whom:				Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/net/gnomenettool/Makefile,v 1.11 2005/10/04 03:12:16 ahze Exp $
#

PORTNAME=	gnomenettool
PORTVERSION=	1.4.1
PORTEPOCH=	1
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-nettool/1.4
DISTNAME=	gnome-nettool-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A GNOME utility that provides network information statistics

USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack intlhack gnomeprefix libglade2 gconf2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CFLAGS+=	-DHAVE_SOCKADDR_SA_LEN

post-install:
	${MKDIR} ${PREFIX}/share/gnome/pixmaps
	${LN} -sf ${PREFIX}/share/gnome/gnome-nettool/pixmaps/gnome-nettool.png \
		${PREFIX}/share/gnome/pixmaps/gnome-nettool.png

.include <bsd.port.mk>
