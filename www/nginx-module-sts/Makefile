PORTNAME=	nginx-module-sts
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.0
CATEGORIES=	www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Sources of the sts modules for the NGINX ports
WWW=		https://github.com/sysadmin-labs/nginx-sts-module

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	sysadmin-labs
GH_PROJECT=	nginx-sts-module

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

_MODDIR=	share/nginx/modules/${PORTNAME}
MODULESDIR=	${PREFIX}/${_MODDIR}

_MODFILES=	src/ngx_http_stream_server_traffic_status_control.c \
		src/ngx_http_stream_server_traffic_status_control.h \
		src/ngx_http_stream_server_traffic_status_display.c \
		src/ngx_http_stream_server_traffic_status_display.h \
		src/ngx_http_stream_server_traffic_status_display_json.c \
		src/ngx_http_stream_server_traffic_status_display_json.h \
		src/ngx_http_stream_server_traffic_status_display_prometheus.c \
		src/ngx_http_stream_server_traffic_status_display_prometheus.h \
		src/ngx_http_stream_server_traffic_status_filter.c \
		src/ngx_http_stream_server_traffic_status_filter.h \
		src/ngx_http_stream_server_traffic_status_module.c \
		src/ngx_http_stream_server_traffic_status_module.h \
		src/ngx_http_stream_server_traffic_status_module_html.h \
		src/ngx_http_stream_server_traffic_status_node.c \
		src/ngx_http_stream_server_traffic_status_node.h \
		src/ngx_http_stream_server_traffic_status_shm.c \
		src/ngx_http_stream_server_traffic_status_shm.h \
		src/ngx_http_stream_server_traffic_status_string.c \
		src/ngx_http_stream_server_traffic_status_string.h \
		src/ngx_stream_server_traffic_status_filter.c \
		src/ngx_stream_server_traffic_status_filter.h \
		src/ngx_stream_server_traffic_status_limit.c \
		src/ngx_stream_server_traffic_status_limit.h \
		src/ngx_stream_server_traffic_status_module.c \
		src/ngx_stream_server_traffic_status_module.h \
		src/ngx_stream_server_traffic_status_node.c \
		src/ngx_stream_server_traffic_status_node.h \
		src/ngx_stream_server_traffic_status_shm.c \
		src/ngx_stream_server_traffic_status_shm.h \
		src/ngx_stream_server_traffic_status_string.c \
		src/ngx_stream_server_traffic_status_string.h \
		src/ngx_stream_server_traffic_status_variables.c \
		src/ngx_stream_server_traffic_status_variables.h \
		src/ngx_sts_layout_check.c

PLIST_FILES=	${_MODDIR}/config \
		${_MODFILES:S!^!${_MODDIR}/!}

do-install:
	@${MKDIR} ${STAGEDIR}${MODULESDIR}/src
	${INSTALL_DATA} ${WRKSRC}/config ${STAGEDIR}${MODULESDIR}
	${INSTALL_DATA} ${_MODFILES:S!^!${WRKSRC}/!} ${STAGEDIR}${MODULESDIR}/src

.include <bsd.port.mk>
