PORTNAME=	nginx-module-srcache
DISTVERSIONPREFIX=	v
DISTVERSION=	0.34
CATEGORIES=	www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Sources of the srcache module for the NGINX ports
WWW=		https://github.com/openresty/srcache-nginx-module

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	openresty
GH_PROJECT=	srcache-nginx-module

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

_MODDIR=	share/nginx/modules/${PORTNAME}
MODULESDIR=	${PREFIX}/${_MODDIR}

PLIST_FILES=	${_MODDIR}/config \
		${_MODDIR}/src/ddebug.h \
		${_MODDIR}/src/ngx_http_srcache_fetch.c \
		${_MODDIR}/src/ngx_http_srcache_fetch.h \
		${_MODDIR}/src/ngx_http_srcache_filter_module.c \
		${_MODDIR}/src/ngx_http_srcache_filter_module.h \
		${_MODDIR}/src/ngx_http_srcache_headers.c \
		${_MODDIR}/src/ngx_http_srcache_headers.h \
		${_MODDIR}/src/ngx_http_srcache_store.c \
		${_MODDIR}/src/ngx_http_srcache_store.h \
		${_MODDIR}/src/ngx_http_srcache_util.c \
		${_MODDIR}/src/ngx_http_srcache_util.h \
		${_MODDIR}/src/ngx_http_srcache_var.c \
		${_MODDIR}/src/ngx_http_srcache_var.h

do-install:
	@${MKDIR} ${STAGEDIR}${MODULESDIR}/src
	${INSTALL_DATA} ${WRKSRC}/config ${STAGEDIR}${MODULESDIR}
	${INSTALL_DATA} ${WRKSRC}/src/* ${STAGEDIR}${MODULESDIR}/src

.include <bsd.port.mk>
