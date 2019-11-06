# Created by: Pedro F. Giffuni
# $FreeBSD$

PORTNAME=	tfel
PORTVERSION=	3.1.2
PORTREVISION=	7
CATEGORIES=	science
MASTER_SITES=	SF/${PORTNAME}/
PKGNAMESUFFIX=	-mfront

MAINTAINER=	pfg@FreeBSD.org
COMMENT=	Code generation tool dedicated to material knowledge

BROKEN=		unfetchable

LICENSE=	GPLv3

BUILD_DEPENDS=	gnuplot:math/gnuplot
RUN_DEPENDS=	gnuplot:math/gnuplot

USES=		cmake compiler:c++0x tar:bzip2

OPTIONS_DEFINE=		DOCS PYTHON
OPTIONS_DEFAULT=	PYTHON
OPTIONS_SUB=		yes

PYTHON_LIB_DEPENDS=	${PY_BOOST}
PYTHON_USES=		localbase python:2.7
PYTHON_CMAKE_ARGS=	`-Denable-python=ON -Denable-python-bindings=ON`
PYTHON_CMAKE_ARGS+=	-Denable-broken-boost-python-module-visibility-handling

CMAKE_ARGS+=	-Denable-aster=ON
CMAKE_ARGS+=	-Denable-calculix=ON
USE_LDCONFIG=	yes

.ifdef PACKAGE_BUILDING
CMAKE_ARGS+=	-Denable-portable-build=ON
.endif

TEST_TARGET=	check

.include <bsd.port.mk>
