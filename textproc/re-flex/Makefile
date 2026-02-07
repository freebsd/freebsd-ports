PORTNAME=	re-flex
PORTVERSION=	6.0.0
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Regex-centric, fast and flexible scanner generator for C++
WWW=		https://www.genivia.com/reflex.html

LICENSE=	BSD3CLAUSE

USES=		compiler:c++11-lib cmake

OPTIONS_DEFINE=	SIMD
SIMD_CMAKE_OFF=	-DUSE_AVX512BW:BOOL=OFF -DUSE_AVX2:BOOL=OFF \
		-DUSE_SSE2:BOOL=OFF -DUSE_NEON:BOOL=OFF

CONFLICTS_INSTALL=	reflex

USE_GITHUB=	yes
GH_ACCOUNT=	Genivia
GH_PROJECT=	RE-flex

post-patch:
	${REINPLACE_CMD} \
		's|reflex_static_lib|reflex|; s|reflex_shared_lib|reflex|' \
		${WRKSRC}/CMakeLists.txt

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/reflex
	(cd ${WRKSRC}/include/reflex && \
	 ${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/include/reflex)
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/lex.vim ${STAGEDIR}${DATADIR}/lex.vim
	${INSTALL_MAN} ${WRKSRC}/doc/man/reflex.1 ${STAGEDIR}/${PREFIX}/share/man/man1/
	@${MKDIR} ${STAGEDIR}${PREFIX}/libdata/pkgconfig
	${INSTALL_DATA} ${WRKSRC}/reflex.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig

.include <bsd.port.mk>
