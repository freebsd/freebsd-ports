PORTNAME=	partitions
DISTVERSION=	1.10-7
PORTREVISION=	1
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Additive Partitions of Integers
WWW=		https://cran.r-project.org/web/packages/partitions/

LICENSE=	GPLv3+

RUN_DEPENDS=	R-cran-gmp>=0.5.1:math/R-cran-gmp \
		R-cran-polynom>=0:math/R-cran-polynom \
		R-cran-sets>=0:math/R-cran-sets \
		R-cran-mathjaxr>=0:math/R-cran-mathjaxr \
		R-cran-Rdpack>=0:devel/R-cran-Rdpack

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
