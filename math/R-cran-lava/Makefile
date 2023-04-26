PORTNAME=	lava
DISTVERSION=	1.7.2.1
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Latent Variable Models
WWW=		https://cran.r-project.org/web/packages/lava/

LICENSE=	GPLv3

CRAN_DEPENDS=	R-cran-future.apply>0:devel/R-cran-future.apply \
		R-cran-numDeriv>0:math/R-cran-numDeriv \
		R-cran-progressr>0:devel/R-cran-progressr \
		R-cran-SQUAREM>0:math/R-cran-SQUAREM
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
