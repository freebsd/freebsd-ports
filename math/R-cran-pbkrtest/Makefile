# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pbkrtest
DISTVERSION=	0.5.1
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Parametric bootstrap and Kenward-Roger-based methods for mixed model comparison

LICENSE=	GPLv2+

CRAN_DEPENDS=	R-cran-lme4>=1.1.10:math/R-cran-lme4 \
		R-cran-broom>0:devel/R-cran-broom \
		R-cran-dplyr>0:math/R-cran-dplyr \
		R-cran-magrittr>0:devel/R-cran-magrittr \
		R-cran-numDeriv>0:math/R-cran-numDeriv \
		R-cran-knitr>0:print/R-cran-knitr
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=	cran:auto-plist

.include <bsd.port.mk>
