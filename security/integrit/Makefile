# ex:ts=8
# New ports collection makefile for:	integrit
# Date created:			Dec 30, 2000
# Whom:				Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	integrit
PORTVERSION=	3.00.05
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/$/-beta/}

MAINTAINER=	josb@cncdsl.com

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}-beta
GNU_CONFIGURE=	yes
ALL_TARGET=	${PORTNAME} utils

MAN1=	i-ls.1 i-viewdb.1 integrit.1

.include <bsd.port.mk>
