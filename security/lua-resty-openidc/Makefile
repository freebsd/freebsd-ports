PORTNAME=	lua-resty-openidc
DISTVERSIONPREFIX=v
DISTVERSION=	1.7.6
CATEGORIES=	security

MAINTAINER=	netchild@FreeBSD.org
COMMENT=	OpenID Connect and/or OAuth 2.0 functionality for OpenResty / ngx_lua
WWW=		https://github.com/zmartzone/lua-resty-openidc

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	luajit-openresty>=2.1:lang/luajit-openresty \
		lua51-cjson>0:devel/lua-cjson@lua51 \
		${LUA_MODSHAREDIR}/resty/http.lua:www/lua-resty-http \
		${LUA_MODSHAREDIR}/resty/session.lua:www/lua-resty-session \
		${LUA_MODSHAREDIR}/resty/jwt.lua:security/lua-resty-jwt \

USE_GITHUB=	yes
GH_ACCOUNT=	zmartzone

NO_ARCH=	yes
NO_BUILD=	yes

LUA_MODSHAREDIR=${LOCALBASE}/share/lua/5.1

PLIST_FILES+=	${LUA_MODSHAREDIR}/resty/openidc.lua

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
