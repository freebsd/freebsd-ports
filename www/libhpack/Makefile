# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libhpack
PORTVERSION=	0.0.20140329
CATEGORIES=	www
MASTER_SITES=	LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Implementation of HPACK (Header compression for HTTP/2.0)

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libcheck.so:${PORTSDIR}/devel/libcheck

CMAKE_ARGS=	-DBUILD_DOCS=OFF \
		-DBUILD_TESTS=OFF \
		-DENABLE_GCOV=OFF \
		-DUSE_VALGRIND=OFF
USE_LDCONFIG=	yes
USES=		cmake pkgconfig python:2,build shebangfix tar:xz

SHEBANG_FILES=	gen-config.py libhpack/huffman-gen.py

post-patch:
	@${REINPLACE_CMD} -e 's|STATIC|SHARED|' ${WRKSRC}/libchula/CMakeLists.txt ${WRKSRC}/libhpack/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|$${CMAKE_INSTALL_LIBDIR}/pkgconfig|libdata/pkgconfig|' ${WRKSRC}/CMakeLists.txt ${WRKSRC}/libchula/CMakeLists.txt

.include <bsd.port.mk>
