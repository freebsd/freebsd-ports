PORTNAME=	optimx
DISTVERSION=	2023-10.21
CATEGORIES=	misc
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Expanded Replacement and Extension of the 'optim' Function
WWW=		https://cran.r-project.org/web/packages/optimx/

LICENSE=	GPLv2

CRAN_DEPENDS=	R-cran-nloptr>0:math/R-cran-nloptr \
		R-cran-numDeriv>0:math/R-cran-numDeriv \
		R-cran-pracma>0:math/R-cran-pracma
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
