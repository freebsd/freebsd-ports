PORTNAME=	faup
DISTVERSION=	1.5-48
PORTREVISION=	1
DISTVERSIONPREFIX=	v
DISTVERSIONSUFFIX=	-g88dbbe2
CATEGORIES=	www devel
MASTER_SITES=	GH LOCAL/antoine

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Fast URL decoder library

LICENSE=	WTFPL
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	stricaud

USES=		cmake compiler:c++11-lang lua
USE_LDCONFIG=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} "s,LUA_VERSION,LUA_VERSION_STRING, ; \
		s,pkg_check_modules(LUA lua>=5.1),FIND_PACKAGE(Lua REQUIRED), ; \
		s,LUA_INCLUDE_DIRS,LUA_INCLUDE_DIR, ; \
		s,LUA_LDFLAGS,LUA_LIBRARIES," \
		${WRKSRC}/CMakeLists.txt \
		${WRKSRC}/src/lib/CMakeLists.txt \
		${WRKSRC}/src/tools/CMakeLists.txt

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
