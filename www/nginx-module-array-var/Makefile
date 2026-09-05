PORTNAME=	nginx-module-array-var
DISTVERSIONPREFIX=	v
DISTVERSION=	0.06
CATEGORIES=	www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Sources of the array_var module for the NGINX ports
WWW=		https://github.com/openresty/array-var-nginx-module

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	openresty
GH_PROJECT=	array-var-nginx-module

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

_MODDIR=	share/nginx/modules/${PORTNAME}
MODULESDIR=	${PREFIX}/${_MODDIR}

PLIST_FILES=	${_MODDIR}/config \
		${_MODDIR}/src/ddebug.h \
		${_MODDIR}/src/ngx_http_array_var_module.c \
		${_MODDIR}/src/ngx_http_array_var_util.c \
		${_MODDIR}/src/ngx_http_array_var_util.h

do-install:
	@${MKDIR} ${STAGEDIR}${MODULESDIR}/src
	${INSTALL_DATA} ${WRKSRC}/config ${STAGEDIR}${MODULESDIR}
	${INSTALL_DATA} ${WRKSRC}/src/ddebug.h \
		${WRKSRC}/src/ngx_http_array_var_module.c \
		${WRKSRC}/src/ngx_http_array_var_util.c \
		${WRKSRC}/src/ngx_http_array_var_util.h \
		${STAGEDIR}${MODULESDIR}/src

.include <bsd.port.mk>
