PORTNAME=	lua-resty-session
DISTVERSIONPREFIX=v
DISTVERSION=	4.0.5
CATEGORIES=	www

MAINTAINER=	netchild@FreeBSD.org
COMMENT=	Lua session library for OpenResty / ngx_lua
WWW=		https://github.com/bungle/lua-resty-session

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	luajit-openresty>=2.1:lang/luajit-openresty
# XXX: deps for filesystem, postgres, redis backends missing

USE_GITHUB=	yes
GH_ACCOUNT=	bungle

NO_ARCH=	yes
NO_BUILD=	yes

LUA_MODSHAREDIR=${LOCALBASE}/share/lua/5.1

PLIST_FILES+=	${LUA_MODSHAREDIR}/resty/session/dshm.lua \
		${LUA_MODSHAREDIR}/resty/session/file.lua \
		${LUA_MODSHAREDIR}/resty/session/file/thread.lua \
		${LUA_MODSHAREDIR}/resty/session/file/utils.lua \
		${LUA_MODSHAREDIR}/resty/session/memcached.lua \
		${LUA_MODSHAREDIR}/resty/session/mysql.lua \
		${LUA_MODSHAREDIR}/resty/session/postgres.lua \
		${LUA_MODSHAREDIR}/resty/session/redis.lua \
		${LUA_MODSHAREDIR}/resty/session/redis/cluster.lua \
		${LUA_MODSHAREDIR}/resty/session/redis/common.lua \
		${LUA_MODSHAREDIR}/resty/session/redis/sentinel.lua \
		${LUA_MODSHAREDIR}/resty/session/shm.lua \
		${LUA_MODSHAREDIR}/resty/session/utils.lua \
		${LUA_MODSHAREDIR}/resty/session.lua

PORTDOCS=	classes/resty.session.html \
		classes/session.html \
		index.html \
		ldoc.css \
		modules/resty.session.dshm.html \
		modules/resty.session.file-thread.html \
		modules/resty.session.file.html \
		modules/resty.session.file.thread.html \
		modules/resty.session.file.utils.html \
		modules/resty.session.html \
		modules/resty.session.memcached.html \
		modules/resty.session.mysql.html \
		modules/resty.session.postgres.html \
		modules/resty.session.redis-cluster.html \
		modules/resty.session.redis-sentinel.html \
		modules/resty.session.redis.cluster.html \
		modules/resty.session.redis.common.html \
		modules/resty.session.redis.html \
		modules/resty.session.redis.sentinel.html \
		modules/resty.session.shm.html \
		modules/resty.session.utils.html \
		README.md

DOCSDIR=	${PREFIX}/share/doc/lua${LUA_VER_STR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${LUA_MODSHAREDIR}
	@(cd ${WRKSRC}/lib && ${COPYTREE_SHARE} . ${STAGEDIR}${LUA_MODSHAREDIR} "-name *\.lua")

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} "-type f")

.include <bsd.port.mk>
