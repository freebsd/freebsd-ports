PORTNAME=	dSFMT
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.5
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Double precision SIMD-oriented Fast Mersenne Twister
WWW=		http://www.math.sci.hiroshima-u.ac.jp/m-mat/MT/SFMT/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USE_GITHUB=	yes
GH_ACCOUNT=	MersenneTwister-Lab
USE_LDCONFIG=	yes

USE_CSTD=	c99
CFLAGS+=	-DNDEBUG -DDSFMT_MEXP=19937 -DDSFMT_DO_NOT_USE_OLD_NAMES \
		-fPIC -DDSFMT_SHLIB -finline-functions -fomit-frame-pointer \
		-fno-strict-aliasing -Wall -shared
CFLAGS_amd64=	-DHAVE_SSE2
LDFLAGS+=	-Wl,-soname,libdSFMT.so.0

OPTIONS_DEFINE=		DOCS OPTIMIZED_CFLAGS
OPTIONS_DEFAULT=	OPTIMIZED_CFLAGS

OPTIMIZED_CFLAGS_CFLAGS=	-O3

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
TEST_TARGET=	sse2-check
MAKE_FLAGS=	SSE2FLAGS="-DHAVE_SSE2" -f
.else
TEST_TARGET=	std-check
.endif

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} ${LDFLAGS} dSFMT.c -o libdSFMT.so.0)

do-install:
	${INSTALL_DATA} ${WRKSRC}/dSFMT.h ${STAGEDIR}${PREFIX}/include/
	${INSTALL_LIB} ${WRKSRC}/libdSFMT.so.0 ${STAGEDIR}${PREFIX}/lib
	${RLN} ${STAGEDIR}${PREFIX}/lib/libdSFMT.so.0 \
		${STAGEDIR}${PREFIX}/lib/libdSFMT.so

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/README.* ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/html && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/html)

do-test:
	${REINPLACE_CMD} -e '/^CC =/d;/^CCFLAGS =/d' ${WRKSRC}/Makefile
	(cd ${WRKSRC} && ${DO_MAKE_BUILD} ${TEST_TARGET})

.include <bsd.port.post.mk>
