PORTNAME=	metadat
DISTVERSION=	1.6-0
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	chris.longros@gmail.com
COMMENT=	Meta-analysis datasets
WWW=		https://cran.r-project.org/package=metadat

LICENSE=	GPLv2+

CRAN_DEPENDS=	R-cran-mathjaxr>0:math/R-cran-mathjaxr
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-digest>0:security/R-cran-digest \
		R-cran-testthat>0:devel/R-cran-testthat

USES=		cran:auto-plist

NO_ARCH=	yes

.include <bsd.port.mk>
