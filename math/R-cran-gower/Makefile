# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gower
DISTVERSION=	0.2.1
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Gower's Distance

LICENSE=	GPLv3

USES=		cran:auto-plist,compiles

OPTIONS_DEFINE=	OPENMP
OPTIONS_DEFAULT=	OPENMP

OPENMP_LIB_DEPENDS=	libomp.so:devel/openmp

.include <bsd.port.mk>
