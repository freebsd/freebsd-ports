PORTNAME=	utf8
DISTVERSION=	1.2.6
CATEGORIES=	textproc
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Unicode Text Processing
WWW=		https://cran.r-project.org/package=utf8

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	R-cran-cli>0:devel/R-cran-cli \
		R-cran-covr>0:devel/R-cran-covr \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-rlang>0:devel/R-cran-rlang \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-testthat>=3.0.0:devel/R-cran-testthat \
		R-cran-withr>0:devel/R-cran-withr

USES=		cran:auto-plist,compiles

# https://github.com/patperry/r-utf8/issues/45
TESTING_UNSAFE=	yes

.include <bsd.port.mk>
