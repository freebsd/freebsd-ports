# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libhpack
PORTVERSION=	0.0.20140710
CATEGORIES=	www
MASTER_SITES=	GH:libhpack \
		https://raw.github.com/http2/http2-spec/master/:ec_xml
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:libhpack \
		draft-ietf-httpbis-header-compression.xml:ec_xml
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Implementation of HPACK (Header compression for HTTP/2.0)

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcheck.so:devel/libcheck

CMAKE_ARGS=	-DBUILD_DOCS=OFF \
		-DBUILD_TESTS=OFF \
		-DENABLE_GCOV=OFF \
		-DLINUX=ON \
		-DUSE_VALGRIND=OFF
MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	yes
USES=		cmake pathfix pkgconfig python:2,build shebangfix

GH_ACCOUNT=	alobbs
GH_TAGNAME=	b0ade19
USE_GITHUB=	yes

SHEBANG_FILES=	gen-config.py \
		libhpack/huffman-gen.py \
		tools/auto-ret.py \
		CI/src-check.py

post-extract:
	@${CP} ${DISTDIR}/draft-ietf-httpbis-header-compression.xml ${WRKSRC}/libhpack/

post-patch:
	@${REINPLACE_CMD} -e 's|STATIC|SHARED|' ${WRKSRC}/libchula/CMakeLists.txt ${WRKSRC}/libhpack/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|$${CMAKE_INSTALL_LIBDIR}/pkgconfig|libdata/pkgconfig|' ${WRKSRC}/CMakeLists.txt ${WRKSRC}/libchula/CMakeLists.txt

.include <bsd.port.mk>
