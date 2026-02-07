PORTNAME=	lua-resty-session
DISTVERSIONPREFIX=v
DISTVERSION=	3.10
CATEGORIES=	www
PKGNAMESUFFIX=	3

MAINTAINER=	baptiste@bapt.name
COMMENT=	Lua session library for OpenResty / ngx_lua Version 3.x
WWW=		https://github.com/bungle/lua-resty-session

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	luajit-openresty>=2.1:lang/luajit-openresty
# XXX: deps for filesystem, postgres, redis backends missing

CONFLICTS_INSTALL=	lua-resty-session-4*

USE_GITHUB=	yes
GH_ACCOUNT=	bungle

NO_ARCH=	yes
NO_BUILD=	yes

LUA_MODSHAREDIR=${LOCALBASE}/share/lua/5.1

PLIST_FILES+=	${LUA_MODSHAREDIR}/resty/session.lua \
		${LUA_MODSHAREDIR}/resty/session/ciphers/aes.lua \
		${LUA_MODSHAREDIR}/resty/session/ciphers/none.lua \
		${LUA_MODSHAREDIR}/resty/session/compressors/none.lua \
		${LUA_MODSHAREDIR}/resty/session/compressors/zlib.lua \
		${LUA_MODSHAREDIR}/resty/session/encoders/base16.lua \
		${LUA_MODSHAREDIR}/resty/session/encoders/base64.lua \
		${LUA_MODSHAREDIR}/resty/session/encoders/hex.lua \
		${LUA_MODSHAREDIR}/resty/session/hmac/sha1.lua \
		${LUA_MODSHAREDIR}/resty/session/identifiers/random.lua \
		${LUA_MODSHAREDIR}/resty/session/serializers/json.lua \
		${LUA_MODSHAREDIR}/resty/session/storage/cookie.lua \
		${LUA_MODSHAREDIR}/resty/session/storage/dshm.lua \
		${LUA_MODSHAREDIR}/resty/session/storage/memcache.lua \
		${LUA_MODSHAREDIR}/resty/session/storage/memcached.lua \
		${LUA_MODSHAREDIR}/resty/session/storage/redis.lua \
		${LUA_MODSHAREDIR}/resty/session/storage/shm.lua \
		${LUA_MODSHAREDIR}/resty/session/strategies/default.lua \
		${LUA_MODSHAREDIR}/resty/session/strategies/regenerate.lua

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
