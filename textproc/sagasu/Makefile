# New ports collection makefile for:	textproc/sagasu
# Date created:				10 Jul 2003
# Whom:					Juan Salaverria <rael@vectorstar.net>
#
# $FreeBSD$

PORTNAME=	sagasu
PORTVERSION=	2.0.6
CATEGORIES=	textproc gnome
MASTER_SITES=	http://www3.sympatico.ca/sarrazip/dev/ \
		http://demian.dyndns.org/src/

MAINTAINER=	rael@vectorstar.net
COMMENT=	Sagasu is a GNOME tool to find strings in a set of files

USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=13
USE_GNOME=	gnomehack gnomeprefix libgnomeui
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		sagasu.1

PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.mk>
