# $FreeBSD$

PORTNAME=	rio
DISTVERSION=	0.5.16
PORTREVISION=	3
CATEGORIES=	textproc
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Swiss-Army Knife for Data I/O

LICENSE=	GPLv2

BUILD_DEPENDS=	R-cran-knitr>0:print/R-cran-knitr
RUN_DEPENDS=	R-cran-data.table>=1.9.8:devel/R-cran-data.table \
		R-cran-tibble>0:devel/R-cran-tibble \
		R-cran-curl>=0.6:ftp/R-cran-curl \
		R-cran-haven>=1.1.0:math/R-cran-haven \
		R-cran-openxlsx>0:textproc/R-cran-openxlsx \
		R-cran-readxl>=0.1.1:textproc/R-cran-readxl
TEST_DEPENDS=	R-cran-jsonlite>0:converters/R-cran-jsonlite \
		R-cran-bit64>0:devel/R-cran-bit64 \
		R-cran-magrittr>0:devel/R-cran-magrittr \
		R-cran-testthat>0:devel/R-cran-testthat \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-readr>0:textproc/R-cran-readr \
		R-cran-xml2>=1.2.0:textproc/R-cran-xml2 \
		R-cran-yaml>0:textproc/R-cran-yaml

USES=		cran:auto-plist

.include <bsd.port.mk>
