PORTNAME=	psych
DISTVERSION=	2.4.6.26
CATEGORIES=	math science
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	drue@therub.org
COMMENT=	Psych package for the R project
WWW=		https://cran.r-project.org/web/packages/psych/index.html

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

CRAN_DEPENDS=	R-cran-GPArotation>0:math/R-cran-GPArotation \
		R-cran-mnormt>0:math/R-cran-mnormt
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-knitr>0:print/R-cran-knitr \
		R-cran-testthat>0:devel/R-cran-testthat

USES=		cran:auto-plist

.include <bsd.port.mk>
