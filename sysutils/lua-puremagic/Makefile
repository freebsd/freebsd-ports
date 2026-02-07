PORTNAME=	puremagic
PORTVERSION=	1.0.1
CATEGORIES=	sysutils
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	mdw@FreeBSD.org
COMMENT=	Lua module that detects the mime type of file based on their contents
WWW=		https://github.com/wbond/puremagic/

LICENSE=	MIT

USES=		lua:module

NO_BUILD=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	wbond
GH_PROJECT=	puremagic

PLIST_FILES=	${LUA_MODSHAREDIR}/puremagic.lua

do-install:
	@${MKDIR} ${STAGEDIR}${LUA_MODSHAREDIR}
	${INSTALL_DATA} ${WRKSRC}/puremagic.lua ${STAGEDIR}${LUA_MODSHAREDIR}

.include <bsd.port.mk>
