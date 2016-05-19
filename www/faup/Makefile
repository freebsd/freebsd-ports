# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	faup
PORTVERSION=	1.5
DISTVERSIONPREFIX=	v
CATEGORIES=	www devel
MASTER_SITES=	GH LOCAL/antoine

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Fast URL decoder library

LICENSE=	WTFPL
LICENSE_NAME=	Do What The [expletive] You Want To Public License, Version 2
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USE_GITHUB=	yes
GH_ACCOUNT=	stricaud

USES=		cmake:outsource lua
USE_LDCONFIG=	yes
CMAKE_ARGS=	-DCMAKE_INSTALL_MANDIR=${PREFIX}/man

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} "s,LUA_VERSION,LUA_VERSION_STRING, ; \
		s,pkg_check_modules(LUA lua>=5.1),FIND_PACKAGE(Lua REQUIRED), ; \
		s,LUA_INCLUDE_DIRS,LUA_INCLUDE_DIR," \
		${WRKSRC}/CMakeLists.txt \
		${WRKSRC}/src/lib/CMakeLists.txt \
		${WRKSRC}/src/tools/CMakeLists.txt

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
