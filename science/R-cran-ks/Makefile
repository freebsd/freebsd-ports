PORTNAME=	ks
PORTVERSION=	1.13.5
CATEGORIES=	science
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Kernel Smoothing

LICENSE=	GPLv2+

RUN_DEPENDS=	R-cran-FNN>0:math/R-cran-FNN	\
		R-cran-mclust>0:math/R-cran-mclust	\
		R-cran-plot3D>0:math/R-cran-plot3D	\
		R-cran-pracma>0:math/R-cran-pracma	\
		R-cran-mvtnorm>0:math/R-cran-mvtnorm	\
		R-cran-kernlab>0:science/R-cran-kernlab	\
		R-cran-multicool>0:devel/R-cran-multicool

USES=		cran:compiles

.include <bsd.port.mk>
