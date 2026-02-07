PORTNAME=	pffft
PORTVERSION=	2022.12.19 # use date because this library is unlikely to ever have releases
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Pretty Fast FFT (PFFFT) library
WWW=		https://github.com/marton78/pffft

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	marton78
GH_TAGNAME=	e0bf595

CMAKE_ON=	BUILD_SHARED_LIBS INSTALL_PFDSP INSTALL_PFFASTCONV

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
CFLAGS+=	-msse2
CXXFLAGS+=	-msse2 # fixes error: always_inline function '_mm_unpacklo_ps' requires target feature 'sse', but would be inlined into function 'pffft_zreorder' that is compiled without support for 'sse'
.elif ${ARCH:Mpowerpc*}
CMAKE_ARGS+=	-DUSE_SIMD:BOOL=OFF #https://github.com/marton78/pffft/issues/55
.endif

post-install: # move headers into a dedicated directory
	cd ${STAGEDIR}${PREFIX} && \
		${MKDIR} include/${PORTNAME} && \
		${MV} include/*.h include/*.hpp include/${PORTNAME}

.include <bsd.port.post.mk>
