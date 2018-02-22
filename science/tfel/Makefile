# Created by: Pedro F. Giffuni
# $FreeBSD$

PORTNAME=	tfel
PORTVERSION=	3.0.2
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	SF/${PORTNAME}/
PKGNAMESUFFIX=	-mfront

MAINTAINER=	pfg@FreeBSD.org
COMMENT=	Code generation tool dedicated to material knowledge

LICENSE=	GPLv3

ONLY_FOR_ARCHS=	amd64 i386

OPTIONS_DEFINE=		GNUPLOT PYTHON
OPTIONS_DEFAULT=	GNUPLOT
OPTIONS_SUB=		yes

GNUPLOT_BUILD_DEPENDS=	gnuplot:math/gnuplot
GNUPLOT_RUN_DEPENDS=	gnuplot:math/gnuplot

PYTHON_LIB_DEPENDS=	${PY_BOOST}
PYTHON_USES=		localbase python:2.7
PYTHON_CONFIGURE_ARGS=	--enable-python-bindings
PYTHON_CONFIGURE_WITH=	boost=${LOCALBASE}

USES=		libtool tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-aster
CONFIGURE_ARGS+=	--enable-abaqus
USE_LDCONFIG=	yes

.ifdef PACKAGE_BUILDING
CONFIGURE_ARGS+=	--enable-portable-build
.endif

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

.include <bsd.port.mk>
