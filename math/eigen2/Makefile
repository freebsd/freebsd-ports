# New ports collection makefile for:	eigen
# Date created:				2008-01-18
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	eigen
PORTVERSION=	1.0.5
CATEGORIES=	math
MASTER_SITES=	http://download.tuxfamily.org/eigen/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Lightweight library for vector and matrix math

BUILD_DEPENDS=	cmake:${PORTSDIR}/devel/cmake

CMAKE?=		${LOCALBASE}/bin/cmake
WRKSRC=		${WRKDIR}/${PORTNAME}/build
MAKE_ENV=	VERBOSE="1"
CMAKE_ARGS=	-DCMAKE_BUILD_TYPE=DEBUG \
		-DCMAKE_INSTALL_PREFIX=${PREFIX} \
		-DCMAKE_C_COMPILER:STRING='${CC}' \
		-DCMAKE_C_FLAGS:STRING="${CFLAGS}" \
		-DCMAKE_CXX_COMPILER:STRING=${CXX} \
		-DCMAKE_CXX_FLAGS:STRING="${CXXFLAGS}"

post-patch:
	${MKDIR} ${WRKSRC}

do-configure:
	cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${CMAKE} ${CMAKE_ARGS} ..

.include <bsd.port.mk>
