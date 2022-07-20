PORTNAME=	gitcreds
DISTVERSION=	0.1.1
CATEGORIES=	security
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ygy@FreeBSD.org
COMMENT=	Query 'git' Credentials from 'R'

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	R-cran-knitr>0:print/R-cran-knitr
TEST_DEPENDS=	R-cran-mockery>0:devel/R-cran-mockery \
		R-cran-testthat>0:devel/R-cran-testthat \
		R-cran-withr>0:devel/R-cran-withr \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown

USES=		cran:auto-plist

.include <bsd.port.mk>
