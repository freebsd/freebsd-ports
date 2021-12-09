# Created by: Guangyuan Yang <ygy@FreeBSD.org>

PORTNAME=	fs
DISTVERSION=	1.5.2
CATEGORIES=	sysutils
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ygy@FreeBSD.org
COMMENT=	Cross-Platform File System Operations Based on 'libuv'

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	R-cran-knitr>0:print/R-cran-knitr
TEST_DEPENDS=	R-cran-covr>0:devel/R-cran-covr \
		R-cran-crayon>0:devel/R-cran-crayon \
		R-cran-pillar>=1.0.0:devel/R-cran-pillar \
		R-cran-testthat>0:devel/R-cran-testthat \
		R-cran-tibble>=1.1.0:devel/R-cran-tibble \
		R-cran-vctrs>=0.3.0:devel/R-cran-vctrs \
		R-cran-withr>0:devel/R-cran-withr \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
