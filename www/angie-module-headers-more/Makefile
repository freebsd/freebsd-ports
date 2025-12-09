PORTNAME=	angie-module-headers-more
MODULE_VERSION=	0.39
MODULE_PORTREVISION=	0
GH_TUPLE=	openresty:headers-more-nginx-module:v${MODULE_VERSION}:module

COMMENT=	Angie headers-more dynamic module
WWW=		https://github.com/openresty/headers-more-nginx-module/

LICENSE_FILE=	${WRKSRC_module}/README.markdown

MASTERDIR=	${.CURDIR}/../../www/angie

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR} \
		 ${STAGEDIR}${MODDIR}

	${INSTALL_LIB} ${WRKSRC}/objs/ngx_http_headers_more_filter_module.so \
	    ${STAGEDIR}${MODDIR}

	${INSTALL_MAN} ${WRKSRC_module}/README.markdown ${STAGEDIR}${DOCSDIR}

do-install-DEBUG-on:
	${INSTALL} ${COPY} -m ${_SHAREMODE} \
	    ${WRKSRC_DEBUG}/objs/ngx_http_headers_more_filter_module.so \
	    ${STAGEDIR}${MODDIR}/ngx_http_headers_more_filter_module-debug.so

.include "${MASTERDIR}/Makefile"
