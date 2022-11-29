PORTNAME=	bcrypt
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3-1
CATEGORIES=	security
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	mdw@FreeBSD.org
COMMENT=	Library providing OpenBSD's bcrypt hash function for Lua
WWW=		https://github.com/mikejsavage/lua-bcrypt/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	luarocks${LUA_VER_STR}:devel/lua-luarocks

USES=		lua:module
USE_GITHUB=	yes
GH_ACCOUNT=	mikejsavage
GH_PROJECT=	lua-bcrypt

PLIST_FILES=	${LUA_MODLIBDIR}/bcrypt.so

post-patch:
	@${REINPLACE_CMD} -e 's|luarocks|luarocks${LUA_VER_STR}|g' ${WRKSRC}/Makefile

do-install:
	@${MKDIR} ${STAGEDIR}${LUA_MODLIBDIR}
	${INSTALL_LIB} ${WRKSRC}/bcrypt.so ${STAGEDIR}${LUA_MODLIBDIR}

.include <bsd.port.mk>
