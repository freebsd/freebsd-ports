# ex:ts=8
# New ports collection makefile for:	integrit
# Date created:			Dec 30, 2000
# Whom:				Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	integrit
PORTVERSION=	3.02.00
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	jos@catnook.com
COMMENT=	A file integrity verification program

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}
GNU_CONFIGURE=	yes
ALL_TARGET=	${PORTNAME} utils

MAN1=	i-ls.1 i-viewdb.1 integrit.1

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		"Does not compile on sparc64"
.endif

.include <bsd.port.post.mk>
