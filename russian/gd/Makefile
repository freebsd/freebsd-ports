# New ports collection makefile for: gd
# Date created:         17 Aug 1998
# Whom:                 gsm@infosite.ru
#
# $FreeBSD$
#

PORTNAME=	gd
PORTVERSION=	1.8.2
CATEGORIES=	russian graphics
MASTER_SITES=	http://www.boutell.com/gd/http/ \
		ftp://ftp.boutell.com/pub/boutell/gd/

MAINTAINER=	gsm@infosite.ru

LIB_DEPENDS=	png.4:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg

pre-install:
	${MKDIR} ${PREFIX}/include/gd

post-install:
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
