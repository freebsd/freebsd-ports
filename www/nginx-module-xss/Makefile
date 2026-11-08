PORTNAME=	nginx-module-xss
DISTVERSIONPREFIX=	v
DISTVERSION=	0.07
CATEGORIES=	www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Sources of the xss module for the NGINX ports
WWW=		https://github.com/openresty/xss-nginx-module

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	openresty
GH_PROJECT=	xss-nginx-module

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

_MODDIR=	share/nginx/modules/${PORTNAME}
MODULESDIR=	${PREFIX}/${_MODDIR}

PLIST_FILES=	${_MODDIR}/config \
		${_MODDIR}/src/ddebug.h \
		${_MODDIR}/src/ngx_http_xss_filter_module.c \
		${_MODDIR}/src/ngx_http_xss_filter_module.h \
		${_MODDIR}/src/ngx_http_xss_util.c \
		${_MODDIR}/src/ngx_http_xss_util.h \
		${_MODDIR}/src/ngx_http_xss_util.rl

do-install:
	@${MKDIR} ${STAGEDIR}${MODULESDIR}/src
	${INSTALL_DATA} ${WRKSRC}/config ${STAGEDIR}${MODULESDIR}
	${INSTALL_DATA} ${WRKSRC}/src/* ${STAGEDIR}${MODULESDIR}/src

.include <bsd.port.mk>
