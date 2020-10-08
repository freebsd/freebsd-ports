# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	readr
PORTVERSION=	1.4.0
CATEGORIES=	textproc
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Read Rectangular Text Data

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

CRAN_DEPENDS=	R-cran-cli>0:devel/R-cran-cli \
		R-cran-clipr>0:devel/R-cran-clipr \
		R-cran-crayon>0:devel/R-cran-crayon \
		R-cran-hms>=0.4.1:devel/R-cran-hms \
		R-cran-rlang>0:devel/R-cran-rlang \
		R-cran-R6>0:devel/R-cran-R6 \
		R-cran-tibble>0:devel/R-cran-tibble \
		R-cran-lifecycle>0:devel/R-cran-lifecycle \
		R-cran-BH>0:devel/R-cran-BH \
		R-cran-cpp11>0:devel/R-cran-cpp11
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		compiler:c++11-lang cran:auto-plist,compiles

.include <bsd.port.mk>
