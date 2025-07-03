PORTNAME=	car
DISTVERSION=	3.1-3
PORTREVISION=	1
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Companion to Applied Regression
WWW=		https://r-forge.r-project.org/projects/car/

LICENSE=	GPLv2+

BUILD_DEPENDS=	R-cran-Formula>=0:math/R-cran-Formula
RUN_DEPENDS=	\
		R-cran-abind>0:devel/R-cran-abind \
		R-cran-carData>=3.0.0:math/R-cran-carData \
		R-cran-lme4>0:math/R-cran-lme4 \
		R-cran-pbkrtest>=0.4.4:math/R-cran-pbkrtest \
		R-cran-quantreg>0:math/R-cran-quantreg \
		R-cran-rio>0:textproc/R-cran-rio \
		R-cran-scales>0:graphics/R-cran-scales \
		R-cran-stringi>=0:textproc/R-cran-stringi
TEST_DEPENDS=	R-cran-lmtest>0:finance/R-cran-lmtest \
		R-cran-MatrixModels>0:math/R-cran-MatrixModels \
		R-cran-SparseM>0:math/R-cran-SparseM \
		R-cran-sandwich>0:math/R-cran-sandwich \
		R-cran-survey>0:math/R-cran-survey

USES=		cran:auto-plist

.include <bsd.port.mk>
