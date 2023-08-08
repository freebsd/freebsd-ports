PORTNAME=	energy
DISTVERSION=	1.7-11
PORTREVISION=	1
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ygy@FreeBSD.org
COMMENT=	E-Statistics: Multivariate Inference via the Energy of Data
WWW=		https://github.com/mariarizzo/energy

LICENSE=	GPLv2+

RUN_DEPENDS=	R-cran-Rcpp>=0.12.6:devel/R-cran-Rcpp \
		R-cran-gsl>0:math/R-cran-gsl

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
