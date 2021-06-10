PORTNAME=	wk
PORTVERSION=	0.4.1
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Lightweight Well-Known Geometry Parsing

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-cpp11>0:devel/R-cran-cpp11
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		compiler:c++11-lang cran:auto-plist,compiles

.include <bsd.port.mk>
