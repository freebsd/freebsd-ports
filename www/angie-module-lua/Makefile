PORTNAME=	angie-module-lua
GH_TUPLE=	openresty:lua-nginx-module:v0.10.28:lua
GH_TUPLE+=	openresty:stream-lua-nginx-module:v0.0.16:lua_stream
GH_TUPLE+=	vision5:ngx_devel_kit:v0.3.4:ndk

COMMENT=	Angie Lua dynamic module

LICENSE_FILE=	${WRKSRC_lua}/README.markdown

LIB_DEPENDS=	libpcre.so:devel/pcre

CONFIGURE_ADD=	--add-dynamic-module=${WRKSRC_lua} \
		--add-dynamic-module=${WRKSRC_lua_stream} \
		--add-dynamic-module=${WRKSRC_ndk}

CONFIGURE_ENV=	LUAJIT_INC=${LUAJIT_INCDIR} \
		LUAJIT_LIB=${LOCALBASE}/lib

RUN_DEPENDS=	angie-module-ndk==${PKGVERSION}:www/angie-module-ndk \
		lua-resty-core>=0.1.29:www/lua-resty-core

USES= 		luajit:luajit-openresty

MASTERDIR=	${.CURDIR}/../../www/angie

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${MODDIR}

.for i in ngx_http_lua_module ngx_stream_lua_module
	${INSTALL_LIB} ${WRKSRC}/objs/${i}.so ${STAGEDIR}${MODDIR}
.endfor

	${INSTALL_MAN} ${WRKSRC_lua}/README.markdown \
		${STAGEDIR}${DOCSDIR}/README.lua-nginx-module.markdown
	${INSTALL_MAN} ${WRKSRC_lua_stream}/README.md \
		${STAGEDIR}${DOCSDIR}/README.stream-lua-nginx-module.md

do-install-DEBUG-on:
.for i in ngx_http_lua_module ngx_stream_lua_module
	${INSTALL} ${COPY} -m ${_SHAREMODE} ${WRKSRC_DEBUG}/objs/${i}.so \
	    ${STAGEDIR}${MODDIR}/${i}-debug.so
.endfor

.include "${MASTERDIR}/Makefile"
