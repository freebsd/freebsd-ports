PORTNAME=	lua-resty-jwt
DISTVERSIONPREFIX=v
DISTVERSION=	0.1.11
CATEGORIES=	security

MAINTAINER=	netchild@FreeBSD.org
COMMENT=	JWT for OpenResty / ngx_lua
WWW=		https://github.com/SkyLothar/lua-resty-jwt

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	luajit-openresty>=2.1:lang/luajit-openresty \
		${LUA_MODSHAREDIR}/resty/hmac.lua:security/lua-resty-hmac

USE_GITHUB=	yes
GH_ACCOUNT=	SkyLothar

NO_ARCH=	yes
NO_BUILD=	yes

LUA_MODSHAREDIR=${LOCALBASE}/share/lua/5.1

PLIST_FILES+=	${LUA_MODSHAREDIR}/resty/evp.lua \
		${LUA_MODSHAREDIR}/resty/jwt-validators.lua \
		${LUA_MODSHAREDIR}/resty/jwt.lua

PORTDOCS=	README.md

DOCSDIR=	${PREFIX}/share/doc/lua${LUA_VER_STR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${LUA_MODSHAREDIR}
	@(cd ${WRKSRC}/lib && ${COPYTREE_SHARE} . ${STAGEDIR}${LUA_MODSHAREDIR} "-name *\.lua")

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
