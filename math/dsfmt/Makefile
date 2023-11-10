PORTNAME=	dSFMT
PORTVERSION=	2.2.5
DISTVERSIONPREFIX=	v
CATEGORIES=	math

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Double precision SIMD-oriented Fast Mersenne Twister
WWW=		http://www.math.sci.hiroshima-u.ac.jp/m-mat/MT/SFMT/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		compiler

USE_GITHUB=	yes
GH_ACCOUNT=	MersenneTwister-Lab

CSTD=		c99
CFLAGS+=	-DDSFMT_MEXP=19937 -fPIC -DDSFMT_SHLIB ${OPTCFLAGS}	\
		-finline-functions -fomit-frame-pointer -fno-strict-aliasing	\
		-Wall -shared
OPTCFLAGS?=	-O3
CFLAGS_amd64=	-msse2 -DHAVE_SSE2
LDFLAGS+=	-Wl,-soname,libdSFMT.so.0
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
TEST_TARGET=	sse2-check
.else
TEST_TARGET=	std-check
.endif

do-build:
	(cd ${WRKSRC} &&	\
	${CC} ${CFLAGS} ${LDFLAGS} dSFMT.c -o libdSFMT.so.0)

do-install:
	${INSTALL_DATA} ${WRKSRC}/dSFMT.h ${STAGEDIR}${PREFIX}/include/
	${INSTALL_LIB} ${WRKSRC}/libdSFMT.so.0 ${STAGEDIR}${PREFIX}/lib
	(cd ${STAGEDIR}${PREFIX}/lib && ${LN} -s libdSFMT.so.0 libdSFMT.so)

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/README.* ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/html && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/html

do-test:
	${REINPLACE_CMD} -e '/^CC =/d;/^CCFLAGS =/d' ${WRKSRC}/Makefile
	(cd ${WRKSRC} && ${DO_MAKE_BUILD} ${TEST_TARGET})

.include <bsd.port.post.mk>
