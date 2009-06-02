# New ports collection makefile for:	igraph
# Date created:		10 May, 2009
# Whom:			Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	igraph
PORTVERSION=	0.5.2
CATEGORIES=	math
MASTER_SITES=	SF
PKGNAMEPREFIX=	R-cran-
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	wenheping@gmail.com
COMMENT=	R extension package for igraph

R_MOD=	yes

.include "${.CURDIR}/../../math/R-cran-sm/files/bsd.cran.mk"

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64: uses i386 assembler
.endif

.include <bsd.port.post.mk>
