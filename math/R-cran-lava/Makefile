PORTNAME=	lava
DISTVERSION=	1.9.2
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Latent Variable Models
WWW=		https://cran.r-project.org/package=lava

LICENSE=	GPLv3

RUN_DEPENDS=	R-cran-cli>0:devel/R-cran-cli \
		R-cran-future.apply>0:devel/R-cran-future.apply \
		R-cran-numDeriv>0:math/R-cran-numDeriv \
		R-cran-progressr>0:devel/R-cran-progressr \
		R-cran-SQUAREM>0:math/R-cran-SQUAREM
TEST_DEPENDS=	R-cran-geepack>0:math/R-cran-geepack \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-Rcpp>0:devel/R-cran-Rcpp \
		R-cran-RcppArmadillo>0:math/R-cran-RcppArmadillo \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-testthat>0:devel/R-cran-testthat

USES=		cran:auto-plist

pre-test:
# R-cran-mets package does not exist yet
	@${LOCALBASE}/bin/Rscript -e 'install.packages("mets", \
		repos = "https://cloud.r-project.org")'

.include <bsd.port.mk>
