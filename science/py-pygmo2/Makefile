# $FreeBSD$

PORTNAME=	pygmo2
DISTVERSIONPREFIX=	v
DISTVERSION=	2.15.0-121
DISTVERSIONSUFFIX=	-gbe6c148
CATEGORIES=	science graphics
#MASTER_SITES=	CHEESESHOP # https://github.com/esa/pygmo2/issues/53
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python platform to perform parallel computations of optimisation tasks

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	pybind11>0:devel/pybind11
LIB_DEPENDS=	libpagmo.so:science/pagmo2 \
		libboost_serialization.so:devel/boost-libs

USES=		cmake compiler:c++11-lang python
USE_GITHUB=	yes
GH_ACCOUNT=	esa
GH_PROJECT=	pygmo2

CMAKE_ON=	PYGMO_ENABLE_IPO

.include <bsd.port.mk>
