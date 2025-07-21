PORTNAME=	pbkrtest
DISTVERSION=	0.5.5
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Parametric bootstrap and Kenward-Roger-based methods for mixed model comparison
WWW=		https://cran.r-project.org/web/packages/pbkrtest/

LICENSE=	GPLv2+

RUN_DEPENDS=	R-cran-broom>0:devel/R-cran-broom \
		R-cran-doBy>=4.6.22:math/R-cran-doBy \
		R-cran-dplyr>0:math/R-cran-dplyr \
		R-cran-lme4>=1.1.31:math/R-cran-lme4 \
		R-cran-numDeriv>0:math/R-cran-numDeriv

USES=		cran:auto-plist

.include <bsd.port.mk>
