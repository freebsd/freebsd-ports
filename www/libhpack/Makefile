# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libhpack
PORTVERSION=	0.0.20140710
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	https://raw.github.com/http2/http2-spec/master/:ec_xml
DISTFILES=	draft-ietf-httpbis-header-compression.xml:ec_xml
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Implementation of HPACK (Header compression for HTTP/2.0)

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

BROKEN_armv6=	fails to compile: Can't define TIME_MAX #'
BROKEN_armv7=	fails to compile: Can't define TIME_MAX #'

LIB_DEPENDS=	libcheck.so:devel/check

CMAKE_OFF=	BUILD_DOCS BUILD_TESTS ENABLE_GCOV USE_VALGRIND
MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	yes
USES=		cmake:insource pathfix pkgconfig python:2.7,build shebangfix

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
	@${REINPLACE_CMD} -e 's|LINUX|BSD|' ${WRKSRC}/libchula-qa/mem_mgr.c

.include <bsd.port.mk>
