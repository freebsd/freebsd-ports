PORTNAME=	pbkrtest
DISTVERSION=	0.5.2
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Parametric bootstrap and Kenward-Roger-based methods for mixed model comparison
WWW=		https://cran.r-project.org/web/packages/pbkrtest/

LICENSE=	GPLv2+

CRAN_DEPENDS=	R-cran-broom>0:devel/R-cran-broom \
		R-cran-dplyr>0:math/R-cran-dplyr \
		R-cran-lme4>=1.1.31:math/R-cran-lme4 \
		R-cran-numDeriv>0:math/R-cran-numDeriv
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
