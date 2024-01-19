PORTNAME=	ks
PORTVERSION=	1.14.2
CATEGORIES=	science
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Kernel Smoothing
WWW=		https://cran.r-project.org/package=ks

LICENSE=	GPLv2+

RUN_DEPENDS=	R-cran-FNN>0:math/R-cran-FNN	\
		R-cran-mclust>0:math/R-cran-mclust	\
		R-cran-plot3D>0:math/R-cran-plot3D	\
		R-cran-pracma>0:math/R-cran-pracma	\
		R-cran-mvtnorm>0:math/R-cran-mvtnorm	\
		R-cran-kernlab>0:science/R-cran-kernlab	\
		R-cran-multicool>0:devel/R-cran-multicool
#TEST_DEPENDS=	R-cran-oz>0:graphics/R-cran-oz

USES=		cran:compiles

.include <bsd.port.mk>
