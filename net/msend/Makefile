# New ports collection makefile for:	msend
# Date created:				Apr 2, 2001
# Whom:					Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	msend
PORTVERSION=	3.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	markp

MAINTAINER=	markp@FreeBSD.org
COMMENT=	A client and server for the RFC1312 message protocol

GNU_CONFIGURE=	yes
CFLAGS+=	-DUSE_READLINE

MAN1=		msend.1
MAN8=		mesgd.8

.include <bsd.port.mk>
