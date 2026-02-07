PORTNAME=	wk
DISTVERSION=	0.9.5
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Lightweight Well-Known Geometry Parsing
WWW=		https://cran.r-project.org/package=wk

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	R-cran-sf>0:math/R-cran-sf \
		R-cran-testthat>0:devel/R-cran-testthat \
		R-cran-tibble>0:devel/R-cran-tibble \
		R-cran-vctrs>0:devel/R-cran-vctrs

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
