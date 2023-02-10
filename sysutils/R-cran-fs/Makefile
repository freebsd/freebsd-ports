PORTNAME=	fs
DISTVERSION=	1.6.0
CATEGORIES=	sysutils
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ygy@FreeBSD.org
COMMENT=	Cross-Platform File System Operations Based on 'libuv'
WWW=		https://fs.r-lib.org

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	R-cran-knitr>0:print/R-cran-knitr
TEST_DEPENDS=	R-cran-covr>0:devel/R-cran-covr \
		R-cran-crayon>0:devel/R-cran-crayon \
		R-cran-pillar>=1.0.0:devel/R-cran-pillar \
		R-cran-testthat>=3.0.0:devel/R-cran-testthat \
		R-cran-tibble>=1.1.0:devel/R-cran-tibble \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-spelling>0:textproc/R-cran-spelling

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
