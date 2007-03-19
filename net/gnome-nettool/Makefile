# New ports collection makefile for:   gnomenetwork
# Date Created:			03 June 2003
# Whom:				Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/net/gnome-nettool/Makefile,v 1.35 2007/03/13 12:41:51 ahze Exp $
#

PORTNAME=	gnome-nettool
PORTVERSION=	2.18.0
PORTEPOCH=	1
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-nettool/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DISTNAME=	gnome-nettool-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A GNOME utility that provides network information statistics

USE_XLIB=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack intlhack gnomeprefix libglade2 gconf2 gnomedocutils
USE_GMAKE=	yes
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CFLAGS+=	-DHAVE_SOCKADDR_SA_LEN

post-install:
	${MKDIR} ${PREFIX}/share/gnome/pixmaps
	${LN} -sf ${PREFIX}/share/gnome/gnome-nettool/pixmaps/gnome-nettool.png \
		${PREFIX}/share/gnome/pixmaps/gnome-nettool.png

.include <bsd.port.mk>
