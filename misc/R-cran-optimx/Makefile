PORTNAME=	optimx
DISTVERSION=	2025-4.9
CATEGORIES=	misc
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Expanded Replacement and Extension of the 'optim' Function
WWW=		https://cran.r-project.org/package=optimx

LICENSE=	GPLv2

CRAN_DEPENDS=	R-cran-nloptr>0:math/R-cran-nloptr \
		R-cran-numDeriv>0:math/R-cran-numDeriv \
		R-cran-pracma>0:math/R-cran-pracma
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-minqa>0:math/R-cran-minqa \
		R-cran-R.rsp>0:textproc/R-cran-R.rsp \
		R-cran-testthat>0:devel/R-cran-testthat

USES=		cran:auto-plist

pre-test:

# Test depends not ported yet
.for pkg in BB dfoptim lbfgsb3c subplex ucminf
	@${LOCALBASE}/bin/Rscript -e 'install.packages("${pkg}", \
		repos = "https://cloud.r-project.org")'
.endfor

.include <bsd.port.mk>
