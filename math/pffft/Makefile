PORTNAME=	pffft
PORTVERSION=	g20210806
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Pretty Fast FFT (PFFFT) library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	marton78
GH_TAGNAME=	9603871

CMAKE_ON=	BUILD_SHARED_LIBS INSTALL_PFDSP INSTALL_PFFASTCONV

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
CXXFLAGS+=	-msse2 # fixes error: always_inline function '_mm_unpacklo_ps' requires target feature 'sse', but would be inlined into function 'pffft_zreorder' that is compiled without support for 'sse'
.endif

post-install: # move headers into a dedicated directory
	cd ${STAGEDIR}${PREFIX} && \
		${MKDIR} include/${PORTNAME} && \
		${MV} include/*.h include/*.hpp include/${PORTNAME}

.include <bsd.port.post.mk>
