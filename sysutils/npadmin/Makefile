# New ports collection makefile for:	npadmin
# Date created:		13 Nov 1998
# Whom:			Dom Mitchell <dom@happygiraffe.net>
#
# $FreeBSD$
#

PORTNAME=	npadmin
PORTVERSION=	0.7
CATEGORIES=	sysutils print
MASTER_SITES=	ftp://ftp.penguincomputing.com/pub/prtools/

MAINTAINER=	dom@happygiraffe.net

ALL_TARGET=	npadmin

MAN1=		npadmin.1

GNU_CONFIGURE=	yes

pre-build:
	${CP} ${FILESDIR}/getopt* ${WRKSRC}

.include <bsd.port.mk>
