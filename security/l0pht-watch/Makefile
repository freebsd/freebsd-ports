# New ports collection makefile for:	l0pht-query
# Date created:		11 Jan 1999
# Whom:			Dom Mitchell <dom@happygiraffe.net>
#
# $FreeBSD$
#

PORTNAME=	l0pht-watch
PORTVERSION=	1.1
CATEGORIES=	security
MASTER_SITES=	http://www.atstake.com/research/tools/
DISTNAME=	${PORTNAME}

MAINTAINER=	dom@happygiraffe.net

WRKSRC=		${WRKDIR}/temp-watch

ALL_TARGET=	OpenBSD

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/temp-watch ${PREFIX}/bin

.include <bsd.port.mk>
