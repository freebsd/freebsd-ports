# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	geepack
DISTVERSION=	1.3-1
PORTREVISION=	1
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Generalized Estimating Equation Package

LICENSE=	GPLv3

CRAN_DEPENDS=	R-cran-broom>=0:devel/R-cran-broom \
		R-cran-magrittr>=0:devel/R-cran-magrittr
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
