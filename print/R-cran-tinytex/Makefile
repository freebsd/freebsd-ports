PORTNAME=	tinytex
DISTVERSION=	0.49
CATEGORIES=	print
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Helper functions to maintain LaTeX distribution
WWW=		https://cran.r-project.org/web/packages/tinytex/

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-xfun>=0.29:misc/R-cran-xfun
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-testit>0:devel/R-cran-testit

USES=		cran:auto-plist

.include <bsd.port.mk>
