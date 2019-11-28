# Created by: Pedro F. Giffuni
# $FreeBSD$

PORTNAME=	tfel
PORTVERSION=	3.2.1
CATEGORIES=	science
MASTER_SITES=	SF/${PORTNAME}/
PKGNAMESUFFIX=	-mfront

MAINTAINER=	pfg@FreeBSD.org
COMMENT=	Code generation tool dedicated to material knowledge

LICENSE=	GPLv3

BUILD_DEPENDS=	gnuplot:math/gnuplot
RUN_DEPENDS=	gnuplot:math/gnuplot

USES=		cmake compiler:c++0x tar:bzip2

OPTIONS_DEFINE=		DOCS PYTHON
OPTIONS_DEFAULT=	PYTHON
OPTIONS_SUB=		yes

PYTHON_USES=		localbase python
PYTHON_BUILD_DEPENDS=	${LOCALBASE}/include/boost/python.hpp:devel/boost-libs
PYTHON_LIB_DEPENDS=	${PY_BOOST}
#XXX This looks wrong but it works, the regular method doesn't !
PYTHON_CMAKE_ON=	-Denable-python=ON -Denable-python-bindings=ON

CMAKE_ON=	enable-aster enable-calculix
USE_LDCONFIG=	yes

.ifdef PACKAGE_BUILDING
CMAKE_ON+=	enable-portable-build
.endif

TEST_TARGET=	check

.include <bsd.port.mk>
