# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libhpack
PORTVERSION=	0.0.20140206
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
USE_PYTHON_BUILD=	2
USES=		cmake pkgconfig shebangfix tar:xz

SHEBANG_FILES=	gen-config.py
python_OLD_CMD=	${SETENV} python
python_CMD=	${PYTHON_CMD}

post-patch:
	@${REINPLACE_CMD} -e 's|STATIC|SHARED|' ${WRKSRC}/libchula/CMakeLists.txt ${WRKSRC}/libhpack/CMakeLists.txt

.include <bsd.port.mk>
