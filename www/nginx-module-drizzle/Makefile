PORTNAME=	nginx-module-drizzle
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.15
CATEGORIES=	www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Sources of the drizzle module for the NGINX ports
WWW=		https://github.com/openresty/drizzle-nginx-module

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	openresty
GH_PROJECT=	drizzle-nginx-module

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

_MODDIR=	share/nginx/modules/${PORTNAME}
MODULESDIR=	${PREFIX}/${_MODDIR}

PLIST_FILES=	${_MODDIR}/config \
		${_MODDIR}/src/ddebug.h \
		${_MODDIR}/src/ngx_http_drizzle_checker.c \
		${_MODDIR}/src/ngx_http_drizzle_checker.h \
		${_MODDIR}/src/ngx_http_drizzle_handler.c \
		${_MODDIR}/src/ngx_http_drizzle_handler.h \
		${_MODDIR}/src/ngx_http_drizzle_keepalive.c \
		${_MODDIR}/src/ngx_http_drizzle_keepalive.h \
		${_MODDIR}/src/ngx_http_drizzle_module.c \
		${_MODDIR}/src/ngx_http_drizzle_module.h \
		${_MODDIR}/src/ngx_http_drizzle_output.c \
		${_MODDIR}/src/ngx_http_drizzle_output.h \
		${_MODDIR}/src/ngx_http_drizzle_processor.c \
		${_MODDIR}/src/ngx_http_drizzle_processor.h \
		${_MODDIR}/src/ngx_http_drizzle_quoting.c \
		${_MODDIR}/src/ngx_http_drizzle_quoting.h \
		${_MODDIR}/src/ngx_http_drizzle_upstream.c \
		${_MODDIR}/src/ngx_http_drizzle_upstream.h \
		${_MODDIR}/src/ngx_http_drizzle_util.c \
		${_MODDIR}/src/ngx_http_drizzle_util.h \
		${_MODDIR}/src/resty_dbd_stream.h

do-install:
	@${MKDIR} ${STAGEDIR}${MODULESDIR}/src
	${INSTALL_DATA} ${WRKSRC}/config ${STAGEDIR}${MODULESDIR}
	${INSTALL_DATA} ${WRKSRC}/src/* ${STAGEDIR}${MODULESDIR}/src

.include <bsd.port.mk>
