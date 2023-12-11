PORTNAME=	lua-resty-hmac
DISTVERSIONSUFFIX=-1
DISTVERSION=	0.06
CATEGORIES=	security

MAINTAINER=	netchild@FreeBSD.org
COMMENT=	HMAC functions for OpenResty / ngx_lua
WWW=		https://github.com/jkeys089/lua-resty-hmac

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	luajit-openresty>=2.1:lang/luajit-openresty \
		${LUA_MODSHAREDIR}/resty/string.lua:devel/lua-resty-string

USE_GITHUB=	yes
GH_ACCOUNT=	jkeys089

NO_ARCH=	yes
NO_BUILD=	yes

LUA_MODSHAREDIR=${LOCALBASE}/share/lua/5.1

PLIST_FILES+=	${LUA_MODSHAREDIR}/resty/hmac.lua

PORTDOCS=	README.markdown

DOCSDIR=	${PREFIX}/share/doc/lua${LUA_VER_STR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${LUA_MODSHAREDIR}
	@(cd ${WRKSRC}/lib && ${COPYTREE_SHARE} . ${STAGEDIR}${LUA_MODSHAREDIR} "-name *\.lua")

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README.markdown ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
