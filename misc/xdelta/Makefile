# New ports collection makefile for:		xdelta
# Date created:					Sun May  4 21:40:06 CDT 1997
# Whom:						jmacd
#
# $FreeBSD$
#

PORTNAME=	xdelta
PORTVERSION=	1.1.1
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.xcf.berkeley.edu/pub/xdelta/

MAINTAINER=	c9710216@atlas.newcastle.edu.au

USE_GLIB=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		xdelta.1

.include <bsd.port.mk>
