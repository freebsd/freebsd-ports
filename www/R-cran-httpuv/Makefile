PORTNAME=	httpuv
PORTVERSION=	1.6.5
CATEGORIES=	www
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	HTTP and WebSocket server library for R

LICENSE=	GPLv2+

CRAN_DEPENDS=	R-cran-Rcpp>=1.0.7:devel/R-cran-Rcpp \
		R-cran-R6>0:devel/R-cran-R6 \
		R-cran-promises>0:devel/R-cran-promises \
		R-cran-later>=0.8.0:devel/R-cran-later
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		compiler:c++11-lang cran:auto-plist,compiles

.include <bsd.port.mk>
