# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	quantreg
PORTVERSION=	5.19
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Quantile Regression

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

RUN_DEPENDS=	R-cran-SparseM>0:${PORTSDIR}/math/R-cran-SparseM \
		R-cran-MatrixModels>0:${PORTSDIR}/math/R-cran-MatrixModels

USES=	cran:auto-plist

.include <bsd.port.mk>
