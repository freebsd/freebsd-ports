PORTNAME=	angie-module-lua
MODULE_VERSION=	0.10.29
MODULE_PORTREVISION=	3
GH_TUPLE=	openresty:lua-nginx-module:v${MODULE_VERSION}:lua
GH_TUPLE+=	openresty:stream-lua-nginx-module:v0.0.16:lua_stream
GH_TUPLE+=	vision5:ngx_devel_kit:v0.3.4:ndk

COMMENT=	Angie Lua dynamic module
WWW=		https://github.com/openresty/lua-nginx-module/

LICENSE_FILE=	${WRKSRC_lua}/README.markdown

LIB_DEPENDS=	libpcre.so:devel/pcre

CONFIGURE_ADD=	--add-dynamic-module=${WRKSRC_lua} \
		--add-dynamic-module=${WRKSRC_lua_stream} \
		--add-dynamic-module=${WRKSRC_ndk}

CONFIGURE_ENV=	LUAJIT_INC=${LUAJIT_INCDIR} \
		LUAJIT_LIB=${LOCALBASE}/lib

RUN_DEPENDS=	angie-module-ndk>=0.3.4,1:www/angie-module-ndk \
		lua-resty-core>=0.1.31:www/lua-resty-core

USES= 		luajit:luajit-openresty

MASTERDIR=	${.CURDIR}/../../www/angie

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR} \
		 ${STAGEDIR}${MODDIR}

	${INSTALL_LIB}  ${WRKSRC}/objs/ngx_http_lua_module.so \
			${WRKSRC}/objs/ngx_stream_lua_module.so \
		${STAGEDIR}${MODDIR}

	${INSTALL_DATA} ${WRKSRC_lua}/README.markdown \
		${STAGEDIR}${DOCSDIR}/README.lua-nginx-module.markdown
	${INSTALL_DATA} ${WRKSRC_lua_stream}/README.md \
		${STAGEDIR}${DOCSDIR}/README.stream-lua-nginx-module.md

do-install-DEBUG-on:
.for i in ngx_http_lua_module ngx_stream_lua_module
	${INSTALL} ${COPY} -m ${_SHAREMODE} ${WRKSRC_DEBUG}/objs/${i}.so \
	    ${STAGEDIR}${MODDIR}/${i}-debug.so
.endfor

.include "${MASTERDIR}/Makefile"
