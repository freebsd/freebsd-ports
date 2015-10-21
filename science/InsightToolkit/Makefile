# Created by: bacon@smithers.neuro.mcw.edu
# $FreeBSD$

PORTNAME=	InsightToolkit
PORTVERSION=	4.8.1
CATEGORIES=	science biology
MASTER_SITES=	SF/itk/itk/4.8

MAINTAINER=	woodsb02@gmail.com
COMMENT=	Insight Toolkit

LICENSE=	APACHE20

USES=		cmake:outsource
CMAKE_ARGS+=	-DBUILD_SHARED_LIBS:BOOL=ON
USE_LDCONFIG=	${PREFIX}/lib/InsightToolkit

OPTIONS_DEFINE=	EXAMPLES TESTING
EXAMPLES_DESC=	Build examples (very time consuming)
TESTING_DESC=	Build testing programs (very time consuming)

EXAMPLES_CMAKE_OFF=	-DBUILD_EXAMPLES:BOOL=OFF
TESTING_CMAKE_OFF=	-DBUILD_TESTING:BOOL=OFF

.include <bsd.port.mk>
