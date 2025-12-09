PORTNAME=	angie-module-redis2
MODULE_VERSION=	0.15
MODULE_PORTREVISION=	0
GH_TUPLE=	openresty:redis2-nginx-module:v${MODULE_VERSION}:module

COMMENT=	Angie redis2 dynamic module
WWW=		https://github.com/openresty/redis2-nginx-module/

LICENSE_FILE=	${WRKSRC_module}/README.markdown

MASTERDIR=	${.CURDIR}/../../www/angie

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR} \
		 ${STAGEDIR}${MODDIR}

	${INSTALL_LIB} ${WRKSRC}/objs/ngx_http_redis2_module.so \
	    ${STAGEDIR}${MODDIR}

	${INSTALL_MAN} ${WRKSRC_module}/README.markdown ${STAGEDIR}${DOCSDIR}

do-install-DEBUG-on:
	${INSTALL} ${COPY} -m ${_SHAREMODE} \
	    ${WRKSRC_DEBUG}/objs/ngx_http_redis2_module.so \
	    ${STAGEDIR}${MODDIR}/ngx_http_redis2_module-debug.so

.include "${MASTERDIR}/Makefile"
