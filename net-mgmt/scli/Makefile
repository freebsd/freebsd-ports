# New ports collection makefile for:	scli
# Date created:		10 September 2001
# Whom:			Michael Lyngbøl <lyngbol@wheel.dk>
#
# $FreeBSD$
#

PORTNAME=	scli
PORTVERSION=	0.2.12
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.ibr.cs.tu-bs.de/pub/local/${PORTNAME}/

MAINTAINER=	lyngbol@wheel.dk

LIB_DEPENDS=	xml2:${PORTSDIR}/textproc/libxml2

GNU_CONFIGURE=	yes
USE_GNOMENG=	yes
USE_GNOME=	glib12

MAN1=		scli.1

.include <bsd.port.mk>
