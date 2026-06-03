PORTNAME=	nginx-module-lua
DISTVERSION=	0.10.29
CATEGORIES=	www
MASTER_SITES=	https://nginx.org/download/:nginx
DISTFILES=	nginx-${NGINX_VERSION}.tar.gz:nginx

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Lua dynamic module for nginx
WWW=		https://github.com/openresty/lua-nginx-module

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	nginx:www/nginx
RUN_DEPENDS=	lua-resty-core>=0.1.32:www/lua-resty-core

USES=		compiler:c11 gmake luajit:luajit-openresty ssl

USE_GITHUB=	nodefault
GH_TUPLE=	openresty:lua-nginx-module:v${DISTVERSION}:lua \
		vision5:ngx_devel_kit:v0.3.4:ndk

NGINX_VERSION=	1.30.2
WRKSRC=		${WRKDIR}/nginx-${NGINX_VERSION}

CONFIGURE_ENV=	LUAJIT_INC=${LOCALBASE}/include/luajit-2.1 \
		LUAJIT_LIB=${LOCALBASE}/lib

CONFIGURE_ARGS=	--with-compat \
		--with-cc-opt="-I${LOCALBASE}/include" \
		--with-ld-opt="-L${LOCALBASE}/lib" \
		--add-dynamic-module=${WRKSRC_ndk} \
		--add-dynamic-module=${WRKSRC_lua}

PLIST_FILES=	libexec/nginx/ngx_http_lua_module.so

do-configure:
	cd ${WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ./configure ${CONFIGURE_ARGS}

do-build:
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} modules

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/nginx
	${INSTALL_LIB} ${WRKSRC}/objs/ngx_http_lua_module.so \
		${STAGEDIR}${PREFIX}/libexec/nginx/ngx_http_lua_module.so

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/nginx/ngx_http_lua_module.so

.include <bsd.port.mk>
