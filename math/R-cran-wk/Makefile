PORTNAME=	wk
DISTVERSION=	0.9.1
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Lightweight Well-Known Geometry Parsing
WWW=		https://cran.r-project.org/web/packages/wk/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	R-cran-testthat>0:devel/R-cran-testthat \
		R-cran-vctrs>0:devel/R-cran-vctrs

USES=		compiler:c++11-lang cran:auto-plist,compiles

.include <bsd.port.mk>
