# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	DoE.base
DISTVERSION=	1.1-3
PORTREVISION=	2
CATEGORIES=	math devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	pfg@FreeBSD.org
COMMENT=	Full Factorials, Orthogonal Arrays and Base Utilities for DoE

LICENSE=	GPLv2+

BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=	cran:auto-plist

CRAN_DEPENDS=	R-cran-conf.design>1:math/R-cran-conf.design	\
		R-cran-combinat>0:math/R-cran-combinat		\
		R-cran-vcd>0:devel/R-cran-vcd \
		R-cran-partitions>=0:math/R-cran-partitions \
		R-cran-numbers>=0:math/R-cran-numbers

.include <bsd.port.mk>
