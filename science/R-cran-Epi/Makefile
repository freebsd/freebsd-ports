# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Epi
PORTVERSION=	2.12
CATEGORIES=	science
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Package for statistical analysis in epidemiology

LICENSE=	GPLv2

CRAN_DEPENDS=	R-cran-cmprsk>0:science/R-cran-cmprsk \
		R-cran-etm>0:science/R-cran-etm \
		R-cran-plyr>0:devel/R-cran-plyr \
		R-cran-numDeriv>0:math/R-cran-numDeriv \
		R-cran-data.table>0:devel/R-cran-data.table
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=	cran:auto-plist,compiles

.include <bsd.port.mk>
