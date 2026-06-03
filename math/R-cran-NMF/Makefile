PORTNAME=	NMF
DISTVERSION=	0.28
PORTREVISION=	1
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Algorithms and Framework for Nonnegative Matrix Factorization
WWW=		https://cran.r-project.org/package=NMF

LICENSE=	GPLv2+

CRAN_DEPENDS=	R-cran-Biobase>0:biology/R-cran-Biobase \
		R-cran-BiocManager>0:biology/R-cran-BiocManager \
		R-cran-colorspace>0:graphics/R-cran-colorspace \
		R-cran-digest>0:security/R-cran-digest \
		R-cran-doParallel>0:devel/R-cran-doParallel \
		R-cran-foreach>0:devel/R-cran-foreach \
		R-cran-ggplot2>0:graphics/R-cran-ggplot2 \
		R-cran-gridBase>0:graphics/R-cran-gridBase \
		R-cran-pkgmaker>=0.20:devel/R-cran-pkgmaker \
		R-cran-RColorBrewer>0:graphics/R-cran-RColorBrewer \
		R-cran-registry>0:devel/R-cran-registry \
		R-cran-reshape2>0:devel/R-cran-reshape2 \
		R-cran-rngtools>=1.2.3:devel/R-cran-rngtools \
		R-cran-stringr>=1.0.0:textproc/R-cran-stringr
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-knitr>0:print/R-cran-knitr

USES=		cran:auto-plist,compiles

pre-test:
# R-cran-corpcor package does not exist yet
	@${LOCALBASE}/bin/Rscript -e 'install.packages("corpcor", \
		repos = "https://cloud.r-project.org")'

.include <bsd.port.mk>
