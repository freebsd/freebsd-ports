PORTNAME=	writexl
DISTVERSION=	1.5.0
CATEGORIES=	textproc
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Export Data Frames to Excel Format
WWW=		https://github.com/ropensci/writexl/

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	R-cran-spelling>=0:textproc/R-cran-spelling \
		R-cran-bit64>=0:devel/R-cran-bit64 \
		R-cran-readxl>=0:textproc/R-cran-readxl
TEST_DEPENDS=	R-cran-testthat>=0:devel/R-cran-testthat

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
