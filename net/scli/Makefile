# New ports collection makefile for:	stools
# Date created:		10 September 2001
# Whom:			Michael Lyngbøl <lyngbol@wheel.dk>
#
# $FreeBSD$
#

PORTNAME=	stools
PORTVERSION=	0.1.20
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.ibr.cs.tu-bs.de/pub/local/${PORTNAME}/

MAINTAINER=	lyngbol@wheel.dk

LIB_DEPENDS=	xml2:${PORTSDIR}/textproc/libxml2

GNU_CONFIGURE=	yes
USE_GTK=	yes

MAN1=		scli.1 stop.1

.include <bsd.port.mk>
