PORTNAME=	nginx-module-push-stream
DISTVERSION=	0.6.2
CATEGORIES=	www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Sources of the push_stream module for the NGINX ports
WWW=		https://github.com/sysadmin-labs/nginx-push-stream-module

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	sysadmin-labs
GH_PROJECT=	nginx-push-stream-module

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

_MODDIR=	share/nginx/modules/${PORTNAME}
MODULESDIR=	${PREFIX}/${_MODDIR}

_MODFILES=	include/ngx_http_push_stream_module.h \
		include/ngx_http_push_stream_module_ipc.h \
		include/ngx_http_push_stream_module_publisher.h \
		include/ngx_http_push_stream_module_setup.h \
		include/ngx_http_push_stream_module_subscriber.h \
		include/ngx_http_push_stream_module_utils.h \
		include/ngx_http_push_stream_module_version.h \
		include/ngx_http_push_stream_module_websocket.h \
		include/ngx_http_push_stream_rbtree_util.h \
		src/ngx_http_push_stream_module.c \
		src/ngx_http_push_stream_module_ipc.c \
		src/ngx_http_push_stream_module_publisher.c \
		src/ngx_http_push_stream_module_setup.c \
		src/ngx_http_push_stream_module_subscriber.c \
		src/ngx_http_push_stream_module_utils.c \
		src/ngx_http_push_stream_module_websocket.c \
		src/ngx_http_push_stream_rbtree_util.c

PLIST_FILES=	${_MODDIR}/config \
		${_MODFILES:S!^!${_MODDIR}/!}

do-install:
	@${MKDIR} ${STAGEDIR}${MODULESDIR}/src \
		${STAGEDIR}${MODULESDIR}/include
	${INSTALL_DATA} ${WRKSRC}/config ${STAGEDIR}${MODULESDIR}
.for f in ${_MODFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${MODULESDIR}/${f:H}
.endfor

.include <bsd.port.mk>
