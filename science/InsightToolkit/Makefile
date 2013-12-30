# Created by: bacon@smithers.neuro.mcw.edu
# $FreeBSD$

PORTNAME=	InsightToolkit
PORTVERSION=	2.8.1
PORTREVISION=	2
CATEGORIES=	science biology
MASTER_SITES=	SF/itk/itk/2.8

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Insight Toolkit

NO_PACKAGE=	License does not allow redistribution of binaries

USES=		cmake
CMAKE_ARGS+=	-DBUILD_SHARED_LIBS:BOOL=ON
USE_LDCONFIG=	${PREFIX}/lib/InsightToolkit

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	EXAMPLES TESTING
EXAMPLES_DESC=	Build examples (very time consuming)
TESTING_DESC=	Build testing programs (very time consuming)

EXAMPLES_CMAKE_OFF=	-DBUILD_EXAMPLES:BOOL=OFF
TESTING_CMAKE_OFF=	-DBUILD_TESTING:BOOL=OFF

post-install:
	@cd ${STAGEDIR}${PREFIX}/lib/InsightToolkit && for lib in *.so; do \
		${LN} -s $$lib.2.8.0 $$lib.2 ; \
	done

.include <bsd.port.mk>
