PORTNAME=	nginx-module-rds-json
DISTVERSIONPREFIX=	v
DISTVERSION=	0.17
CATEGORIES=	www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Sources of the rds_json module for the NGINX ports
WWW=		https://github.com/openresty/rds-json-nginx-module

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	openresty
GH_PROJECT=	rds-json-nginx-module

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

_MODDIR=	share/nginx/modules/${PORTNAME}
MODULESDIR=	${PREFIX}/${_MODDIR}

PLIST_FILES=	${_MODDIR}/config \
		${_MODDIR}/src/ddebug.h \
		${_MODDIR}/src/ngx_http_rds.h \
		${_MODDIR}/src/ngx_http_rds_json_filter_module.c \
		${_MODDIR}/src/ngx_http_rds_json_filter_module.h \
		${_MODDIR}/src/ngx_http_rds_json_handler.c \
		${_MODDIR}/src/ngx_http_rds_json_handler.h \
		${_MODDIR}/src/ngx_http_rds_json_output.c \
		${_MODDIR}/src/ngx_http_rds_json_output.h \
		${_MODDIR}/src/ngx_http_rds_json_processor.c \
		${_MODDIR}/src/ngx_http_rds_json_processor.h \
		${_MODDIR}/src/ngx_http_rds_json_util.c \
		${_MODDIR}/src/ngx_http_rds_json_util.h \
		${_MODDIR}/src/ngx_http_rds_utils.h \
		${_MODDIR}/src/resty_dbd_stream.h

do-install:
	@${MKDIR} ${STAGEDIR}${MODULESDIR}/src
	${INSTALL_DATA} ${WRKSRC}/config ${STAGEDIR}${MODULESDIR}
	${INSTALL_DATA} ${WRKSRC}/src/* ${STAGEDIR}${MODULESDIR}/src

.include <bsd.port.mk>
