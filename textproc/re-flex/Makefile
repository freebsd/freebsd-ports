PORTNAME=	re-flex
PORTVERSION=	3.2.1
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Regex-centric, fast and flexible scanner generator for C++

LICENSE=	BSD3CLAUSE

USES=		compiler:c++11-lib cmake

OPTIONS_DEFINE=	SIMD
SIMD_CMAKE_OFF=	-DUSE_AVX512BW:BOOL=OFF -DUSE_AVX2:BOOL=OFF \
		-DUSE_SSE2:BOOL=OFF -DUSE_NEON:BOOL=OFF

CONFLICTS_INSTALL=	reflex

USE_GITHUB=	yes
GH_ACCOUNT=	Genivia
GH_PROJECT=	RE-flex

TEST_TARGET=	test

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/reflex
	(cd ${WRKSRC}/include/reflex && \
	 ${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/include/reflex)
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/lex.vim ${STAGEDIR}${DATADIR}/lex.vim
	${INSTALL_MAN} ${WRKSRC}/doc/man/reflex.1 ${STAGEDIR}/${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
