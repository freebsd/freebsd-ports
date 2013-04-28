# Created by: bacon@smithers.neuro.mcw.edu
# $FreeBSD$

PORTNAME=	InsightToolkit
PORTVERSION=	2.8.1
PORTREVISION=	2
CATEGORIES=	science biology
MASTER_SITES=	SF/itk/itk/2.8

MAINTAINER=	jwbacon@tds.net
COMMENT=	Insight Toolkit

OPTIONS_DEFINE=	EXAMPLES TESTING
#OPTIONS=	EXAMPLES "Build examples (very time consuming)" off \
#		TESTING  "Build testing programs (very time consuming)" off

USE_LDCONFIG=	${PREFIX}/lib/InsightToolkit
NO_PACKAGE=	License does not allow redistribution of binaries

USES=		cmake
CMAKE_ARGS+=	-DBUILD_SHARED_LIBS:BOOL=ON

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if ! ${PORT_OPTIONS:MEXAMPLES}
CMAKE_ARGS+=	"-DBUILD_EXAMPLES:BOOL=OFF"
.endif

.if ! ${PORT_OPTIONS:MTESTING}
CMAKE_ARGS+=	"-DBUILD_TESTING:BOOL=OFF"
.endif

post-install:
	@for lib in ${PREFIX}/lib/InsightToolkit/*.so ; do \
		${LN} -s $$lib.2.8.0 $$lib.2 ; \
	done
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
