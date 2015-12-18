# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dplyr
DISTVERSION=	0.4.3
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Grammar of Data Manipulation

LICENSE=	MIT

BUILD_DEPENDS=	R-cran-Rcpp>=0.11:${PORTSDIR}/devel/R-cran-Rcpp \
		R-cran-BH>=1.58.0.1:${PORTSDIR}/devel/R-cran-BH \
		R-cran-R6>=0:${PORTSDIR}/devel/R-cran-R6 \
		R-cran-DBI>=0.3:${PORTSDIR}/databases/R-cran-DBI \
		R-cran-magrittr>=0:${PORTSDIR}/devel/R-cran-magrittr \
		R-cran-lazyeval>=0.1.10:${PORTSDIR}/math/R-cran-lazyeval \
		R-cran-assertthat>=0:${PORTSDIR}/math/R-cran-assertthat
RUN_DEPENDS=	R-cran-Rcpp>=0.11:${PORTSDIR}/devel/R-cran-Rcpp \
		R-cran-BH>=1.58.0.1:${PORTSDIR}/devel/R-cran-BH \
		R-cran-R6>=0:${PORTSDIR}/devel/R-cran-R6 \
		R-cran-DBI>=0.3:${PORTSDIR}/databases/R-cran-DBI \
		R-cran-magrittr>=0:${PORTSDIR}/devel/R-cran-magrittr \
		R-cran-lazyeval>=0.1.10:${PORTSDIR}/math/R-cran-lazyeval \
		R-cran-assertthat>=0:${PORTSDIR}/math/R-cran-assertthat

USES=	cran:auto-plist

.include <bsd.port.mk>
