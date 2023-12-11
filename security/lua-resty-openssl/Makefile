PORTNAME=	lua-resty-openssl
DISTVERSION=	1.0.2
CATEGORIES=	security

MAINTAINER=	netchild@FreeBSD.org
COMMENT=	FFI-based OpenSSL binding for OpenResty / ngx_lua
WWW=		https://github.com/fffonion/lua-resty-openssl

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	luajit-openresty>=2.1:lang/luajit-openresty

USES=		ssl
USE_GITHUB=	yes
GH_ACCOUNT=	fffonion

NO_ARCH=	yes
NO_BUILD=	yes

LUA_MODSHAREDIR=${LOCALBASE}/share/lua/5.1

PORTDOCS=	README.md

DOCSDIR=	${PREFIX}/share/doc/lua${LUA_VER_STR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${LUA_MODSHAREDIR}
	@(cd ${WRKSRC}/lib && ${COPYTREE_SHARE} . ${STAGEDIR}${LUA_MODSHAREDIR} "-name *\.lua")

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

gen-plist:
	@${FIND} ${WRKSRC}/lib -type f | ${SED} -e 's:${WRKSRC}/lib:share/lua/5.1:g' \
	    | ${SORT} > pkg-plist.new
	@${FIND} ${WRKSRC}/lib/resty/openssl -type d | ${SED} -e 's:${WRKSRC}/lib:@dir share/lua/5.1:g' \
	    | ${SORT} -r >> pkg-plist.new
	

.include <bsd.port.mk>
