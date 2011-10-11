# New ports collection makefile for:	math/R-cran-SuppDists
# Date created:				April 27, 2010
# Whom:					b.f. <bf@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	SuppDists
DISTVERSION=	1.1-8
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	${MASTER_CRAN_SITES} \
		http://r.research.att.com/benchmarks/:benchmark \
		LOCAL/bf:benchmark
PKGNAMEPREFIX=	R-cran-
DISTFILES=	${PORTNAME}_${DISTVERSION}${EXTRACT_SUFX} \
		${BENCHMARK_SCRIPT}:benchmark
EXTRACT_ONLY=	${PORTNAME}_${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Supplementary distributions and RNG for R

BENCHMARK_SCRIPT=	R-benchmark-25.R
LICENSE=		GPLv2
R_MOD_AUTOPLIST=	yes
USE_R_MOD=		yes
WRKSRC =		${WRKDIR}/${PORTNAME}

.if defined(MAINTAINER_MODE)
USE_DOS2UNIX=	../${BENCHMARK_SCRIPT}

post-extract:
	@${CP} ${_DISTDIR}/${BENCHMARK_SCRIPT} ${WRKDIR}

post-install: benchmark

benchmark:
	@${LOCALBASE}/bin/Rscript --vanilla ${WRKDIR}/${BENCHMARK_SCRIPT}

.endif

.include <bsd.port.mk>
