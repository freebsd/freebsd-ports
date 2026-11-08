PORTNAME=	nginx-module-rds-csv
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10
CATEGORIES=	www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Sources of the rds_csv module for the NGINX ports
WWW=		https://github.com/openresty/rds-csv-nginx-module

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	openresty
GH_PROJECT=	rds-csv-nginx-module

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

_MODDIR=	share/nginx/modules/${PORTNAME}
MODULESDIR=	${PREFIX}/${_MODDIR}

PLIST_FILES=	${_MODDIR}/config \
		${_MODDIR}/src/ddebug.h \
		${_MODDIR}/src/ngx_http_rds.h \
		${_MODDIR}/src/ngx_http_rds_csv_filter_module.c \
		${_MODDIR}/src/ngx_http_rds_csv_filter_module.h \
		${_MODDIR}/src/ngx_http_rds_csv_output.c \
		${_MODDIR}/src/ngx_http_rds_csv_output.h \
		${_MODDIR}/src/ngx_http_rds_csv_processor.c \
		${_MODDIR}/src/ngx_http_rds_csv_processor.h \
		${_MODDIR}/src/ngx_http_rds_csv_util.c \
		${_MODDIR}/src/ngx_http_rds_csv_util.h \
		${_MODDIR}/src/ngx_http_rds_utils.h \
		${_MODDIR}/src/resty_dbd_stream.h

do-install:
	@${MKDIR} ${STAGEDIR}${MODULESDIR}/src
	${INSTALL_DATA} ${WRKSRC}/config ${STAGEDIR}${MODULESDIR}
	${INSTALL_DATA} ${WRKSRC}/src/* ${STAGEDIR}${MODULESDIR}/src

.include <bsd.port.mk>
