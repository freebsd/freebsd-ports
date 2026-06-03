PORTNAME=	ankiR
DISTVERSION=	0.6.0
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	chris.longros@gmail.com
COMMENT=	Read and Analyze Anki Flashcard Databases
WWW=		https://github.com/chrislongros/ankiR

LICENSE=	MIT

RUN_DEPENDS=	R-cran-rlang>0:devel/R-cran-rlang \
		R-cran-jsonlite>0:converters/R-cran-jsonlite \
		R-cran-DBI>0:databases/R-cran-DBI \
		R-cran-RSQLite>0:databases/R-cran-RSQLite \
		R-cran-tibble>0:devel/R-cran-tibble \
		R-cran-scales>0:graphics/R-cran-scales

USES=		cran:auto-plist

.include <bsd.port.mk>
