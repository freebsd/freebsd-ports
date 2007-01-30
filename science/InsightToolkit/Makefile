# New ports collection Makefile for:   Insight Toolkit
# Date created:        10 Aug 2006
# Whom:                bacon@smithers.neuro.mcw.edu
#
# $FreeBSD$
#

PORTNAME=	InsightToolkit
PORTVERSION=	2.8.1
CATEGORIES=	science biology
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	itk

MAINTAINER=	bacon@smithers.neuro.mcw.edu
COMMENT=	Insight Toolkit

BUILD_DEPENDS=	cmake:${PORTSDIR}/devel/cmake

OPTIONS=	EXAMPLES "Build examples (very time consuming)" off \
		TESTING  "Build testing programs (very time consuming)" off

USE_LDCONFIG=	${PREFIX}/lib/InsightToolkit
NO_PACKAGE=	License does not allow redistribution of binaries
BUILD_WRKSRC=	${WRKSRC}/Build
INSTALL_WRKSRC=	${BUILD_WRKSRC}

CMAKE_ARGS=	-DCMAKE_INSTALL_PREFIX:PATH=${PREFIX} \
		-DBUILD_SHARED_LIBS:BOOL=ON

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if !defined(WITH_EXAMPLES)
CMAKE_ARGS+=	"-DBUILD_EXAMPLES:BOOL=OFF"
.endif

.if !defined(WITH_TESTING)
CMAKE_ARGS+=	"-DBUILD_TESTING:BOOL=OFF"
.endif

pre-build:
	@${MKDIR} ${BUILD_WRKSRC}
	@cd ${BUILD_WRKSRC} && cmake ${CMAKE_ARGS} ..

post-install:
	@for lib in ${PREFIX}/lib/InsightToolkit/*.so ; do \
		${LN} -s $$lib.2.8.0 $$lib.2 ; \
	done
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
