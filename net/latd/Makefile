# New ports collection makefile for:   latd
# Date created:        19 December 2003
# Whom:                Tillman Hodgson <tillman@seekingfire.com>
#
# $FreeBSD$
#

PORTNAME=	latd
PORTVERSION=	1.25
CATEGORIES=	net
MASTER_SITES=	SF/linux-decnet/${PORTNAME}/${PORTVERSION}

MAINTAINER=	tillman@seekingfire.com
COMMENT=	The linux-decnet project LAT protocol suite

WRKSRC=		${WRKDIR}/${DISTNAME}

GNU_CONFIGURE=	yes
CFLAGS+=	-Wno-deprecated

MAN1=		llogin.1
MAN5=		latd.conf.5
MAN8=		latd.8 latcp.8 moprc.8

.include <bsd.port.mk>
