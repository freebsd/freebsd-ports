PORTNAME=	nginx-module-memc
DISTVERSIONPREFIX=	v
DISTVERSION=	0.21
CATEGORIES=	www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Sources of the memc module for the NGINX ports
WWW=		https://github.com/openresty/memc-nginx-module

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	openresty
GH_PROJECT=	memc-nginx-module

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

_MODDIR=	share/nginx/modules/${PORTNAME}
MODULESDIR=	${PREFIX}/${_MODDIR}

_MODFILES=	src/ddebug.h \
		src/ngx_http_memc_handler.c \
		src/ngx_http_memc_handler.h \
		src/ngx_http_memc_module.c \
		src/ngx_http_memc_module.h \
		src/ngx_http_memc_request.c \
		src/ngx_http_memc_request.h \
		src/ngx_http_memc_response.c \
		src/ngx_http_memc_response.h \
		src/ngx_http_memc_util.c \
		src/ngx_http_memc_util.h

PLIST_FILES=	${_MODDIR}/config \
		${_MODFILES:S!^!${_MODDIR}/!}

do-install:
	@${MKDIR} ${STAGEDIR}${MODULESDIR}/src
	${INSTALL_DATA} ${WRKSRC}/config ${STAGEDIR}${MODULESDIR}
	${INSTALL_DATA} ${_MODFILES:S!^!${WRKSRC}/!} ${STAGEDIR}${MODULESDIR}/src

.include <bsd.port.mk>
