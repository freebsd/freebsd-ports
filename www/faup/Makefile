# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	faup
PORTVERSION=	1.4.20150118
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
GH_TAGNAME=	af9e5db
GH_COMMIT=	af9e5db

USES=		cmake:outsource lua
USE_LDCONFIG=	yes
CMAKE_ARGS=	-DCMAKE_INSTALL_MANDIR=${PREFIX}/man

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e "s/5.1/${LUA_VER}/g" -e \
		"s/51/${LUA_VER_STR}/g" ${WRKSRC}/cmake/FindLua51.cmake
	@${REINPLACE_CMD} -e "s/LUA51_FOUND/LUA${LUA_VER_STR}_FOUND/g" \
		${WRKSRC}/CMakeLists.txt ${WRKSRC}/src/lib/CMakeLists.txt \
		${WRKSRC}/src/tools/CMakeLists.txt

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
