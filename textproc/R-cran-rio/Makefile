PORTNAME=	rio
DISTVERSION=	1.2.4
CATEGORIES=	textproc
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Swiss-Army knife for data I/O
WWW=		https://github.com/leeper/rio

LICENSE=	GPLv2

RUN_DEPENDS=	R-cran-clipr>0:devel/R-cran-clipr \
		R-cran-curl>=0.6:ftp/R-cran-curl \
		R-cran-data.table>=1.11.2:devel/R-cran-data.table \
		R-cran-haven>=1.1.2:math/R-cran-haven \
		R-cran-jsonlite>0:converters/R-cran-jsonlite \
		R-cran-R.utils>0:devel/R-cran-R.utils \
		R-cran-readr>0:textproc/R-cran-readr \
		R-cran-readxl>=0.1.1:textproc/R-cran-readxl \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-tibble>0:devel/R-cran-tibble \
		R-cran-writexl>0:textproc/R-cran-writexl \
		R-cran-xml2>=1.2.0:textproc/R-cran-xml2 \
		R-cran-yaml>0:textproc/R-cran-yaml
TEST_DEPENDS=	R-cran-bit64>0:devel/R-cran-bit64 \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-magrittr>0:devel/R-cran-magrittr \
		R-cran-stringi>0:textproc/R-cran-stringi \
		R-cran-testthat>0:devel/R-cran-testthat \
		R-cran-withr>0:devel/R-cran-withr

USES=		cran:auto-plist

.include <bsd.port.mk>
