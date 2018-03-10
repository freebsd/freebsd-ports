# Created by: David Naylor <naylor.b.david@gmail.com>
# $FreeBSD$

PORTNAME=	car
DISTVERSION=	2.1-6
PORTREVISION=	1
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	dbn@FreeBSD.org
COMMENT=	Companion to Applied Regression

LICENSE=	GPLv2+

RUN_DEPENDS=	R-cran-pbkrtest>=0.4.4:math/R-cran-pbkrtest \
		R-cran-quantreg>0:math/R-cran-quantreg
TEST_DEPENDS=	R-cran-lmtest>0:finance/R-cran-lmtest \
		R-cran-MatrixModels>0:math/R-cran-MatrixModels \
		R-cran-SparseM>0:math/R-cran-SparseM \
		R-cran-lme4>0:math/R-cran-lme4 \
		R-cran-sandwich>0:math/R-cran-sandwich \
		R-cran-survey>0:math/R-cran-survey

USES=		cran:auto-plist

.include <bsd.port.mk>
