# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	memisc
DISTVERSION=	0.99.21
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Provides an infrastructure for the management of survey data

LICENSE=	GPLv2

CRAN_DEPENDS=	R-cran-repr>0:devel/R-cran-repr \
		R-cran-data.table>0:devel/R-cran-data.table
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=	cran:auto-plist,compiles

.include <bsd.port.mk>
