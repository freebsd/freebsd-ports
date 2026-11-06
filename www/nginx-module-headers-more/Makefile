PORTNAME=	nginx-module-headers-more
DISTVERSIONPREFIX=	v
DISTVERSION=	0.41
CATEGORIES=	www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Sources of the headers_more module for the NGINX ports
WWW=		https://github.com/openresty/headers-more-nginx-module

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	openresty
GH_PROJECT=	headers-more-nginx-module

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

_MODDIR=	share/nginx/modules/${PORTNAME}
MODULESDIR=	${PREFIX}/${_MODDIR}

PLIST_FILES=	${_MODDIR}/config \
		${_MODDIR}/src/ddebug.h \
		${_MODDIR}/src/ngx_http_headers_more_filter_module.c \
		${_MODDIR}/src/ngx_http_headers_more_filter_module.h \
		${_MODDIR}/src/ngx_http_headers_more_headers_in.c \
		${_MODDIR}/src/ngx_http_headers_more_headers_in.h \
		${_MODDIR}/src/ngx_http_headers_more_headers_out.c \
		${_MODDIR}/src/ngx_http_headers_more_headers_out.h \
		${_MODDIR}/src/ngx_http_headers_more_util.c \
		${_MODDIR}/src/ngx_http_headers_more_util.h

do-install:
	@${MKDIR} ${STAGEDIR}${MODULESDIR}/src
	${INSTALL_DATA} ${WRKSRC}/config ${STAGEDIR}${MODULESDIR}
	${INSTALL_DATA} ${WRKSRC}/src/* ${STAGEDIR}${MODULESDIR}/src

.include <bsd.port.mk>
