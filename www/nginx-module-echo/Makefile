PORTNAME=	nginx-module-echo
DISTVERSIONPREFIX=	v
DISTVERSION=	0.66
CATEGORIES=	www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Sources of the echo module for the NGINX ports
WWW=		https://github.com/openresty/echo-nginx-module

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	openresty
GH_PROJECT=	echo-nginx-module

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

_MODDIR=	share/nginx/modules/${PORTNAME}
MODULESDIR=	${PREFIX}/${_MODDIR}

PLIST_FILES=	${_MODDIR}/config \
		${_MODDIR}/src/ddebug.h \
		${_MODDIR}/src/ngx_http_echo_echo.c \
		${_MODDIR}/src/ngx_http_echo_echo.h \
		${_MODDIR}/src/ngx_http_echo_filter.c \
		${_MODDIR}/src/ngx_http_echo_filter.h \
		${_MODDIR}/src/ngx_http_echo_foreach.c \
		${_MODDIR}/src/ngx_http_echo_foreach.h \
		${_MODDIR}/src/ngx_http_echo_handler.c \
		${_MODDIR}/src/ngx_http_echo_handler.h \
		${_MODDIR}/src/ngx_http_echo_location.c \
		${_MODDIR}/src/ngx_http_echo_location.h \
		${_MODDIR}/src/ngx_http_echo_module.c \
		${_MODDIR}/src/ngx_http_echo_module.h \
		${_MODDIR}/src/ngx_http_echo_request_info.c \
		${_MODDIR}/src/ngx_http_echo_request_info.h \
		${_MODDIR}/src/ngx_http_echo_sleep.c \
		${_MODDIR}/src/ngx_http_echo_sleep.h \
		${_MODDIR}/src/ngx_http_echo_subrequest.c \
		${_MODDIR}/src/ngx_http_echo_subrequest.h \
		${_MODDIR}/src/ngx_http_echo_timer.c \
		${_MODDIR}/src/ngx_http_echo_timer.h \
		${_MODDIR}/src/ngx_http_echo_util.c \
		${_MODDIR}/src/ngx_http_echo_util.h \
		${_MODDIR}/src/ngx_http_echo_var.c \
		${_MODDIR}/src/ngx_http_echo_var.h

do-install:
	@${MKDIR} ${STAGEDIR}${MODULESDIR}/src
	${INSTALL_DATA} ${WRKSRC}/config ${STAGEDIR}${MODULESDIR}
	${INSTALL_DATA} ${WRKSRC}/src/* ${STAGEDIR}${MODULESDIR}/src

.include <bsd.port.mk>
