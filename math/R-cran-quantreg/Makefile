PORTNAME=	quantreg
PORTVERSION=	5.94
PORTREVISION=	1
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Quantile Regression
WWW=		https://cran.r-project.org/web/packages/quantreg/

LICENSE=	GPLv2+

CRAN_DEPENDS=	R-cran-SparseM>0:math/R-cran-SparseM \
		R-cran-MatrixModels>0:math/R-cran-MatrixModels
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=	cran:auto-plist,compiles

.include <bsd.port.mk>
