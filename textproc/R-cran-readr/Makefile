PORTNAME=	readr
PORTVERSION=	2.1.6
CATEGORIES=	textproc
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Read Rectangular Text Data
WWW=		https://cran.r-project.org/web/packages/readr/

LICENSE=	MIT

RUN_DEPENDS=	R-cran-cli>=3.2.0:devel/R-cran-cli \
		R-cran-clipr>0:devel/R-cran-clipr \
		R-cran-cpp11>0:devel/R-cran-cpp11 \
		R-cran-crayon>0:devel/R-cran-crayon \
		R-cran-hms>=0.4.1:devel/R-cran-hms \
		R-cran-lifecycle>=0.2.0:devel/R-cran-lifecycle \
		R-cran-R6>0:devel/R-cran-R6 \
		R-cran-rlang>0:devel/R-cran-rlang \
		R-cran-tibble>0:devel/R-cran-tibble \
		R-cran-tzdb>=0.1.1:devel/R-cran-tzdb \
		R-cran-vroom>=1.6.0:textproc/R-cran-vroom

USES=		compiler:c++11-lang cran:auto-plist,compiles

.include <bsd.port.mk>
