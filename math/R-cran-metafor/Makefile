PORTNAME=	metafor
DISTVERSION=	5.2-1
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	longros@FreeBSD.org
COMMENT=	Meta-analysis package for R
WWW=		https://cran.r-project.org/package=metafor

LICENSE=	GPLv2+

CRAN_DEPENDS=	R-cran-digest>0:security/R-cran-digest \
		R-cran-mathjaxr>0:math/R-cran-mathjaxr \
		R-cran-metadat>0:math/R-cran-metadat \
		R-cran-numDeriv>0:math/R-cran-numDeriv \
		R-cran-pbapply>0:devel/R-cran-pbapply
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
