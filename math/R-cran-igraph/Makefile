# New ports collection makefile for:	igraph
# Date created:		10 May, 2009
# Whom:			Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	igraph
PORTVERSION=	0.5.2
PORTREVISION=	6
CATEGORIES=	math
MASTER_SITES=	SF/${PORTNAME}/R%20source%20package/${PORTVERSION}
PKGNAMEPREFIX=	R-cran-
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	wenheping@gmail.com
COMMENT=	R extension package for igraph

BROKEN=		Does not build with R-2.11.0

USE_R_MOD=	yes
R_MOD_AUTOPLIST=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64: uses i386 assembler
.endif

.include <bsd.port.post.mk>
