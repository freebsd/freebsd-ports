PORTNAME=	angie-module-headers-more
GH_TUPLE=	openresty:headers-more-nginx-module:v0.39:module

COMMENT=	Angie headers-more dynamic module

LICENSE_FILE=	${WRKSRC_module}/README.markdown

MASTERDIR=	${.CURDIR}/../../www/angie

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${MODDIR}

	${INSTALL_LIB} ${WRKSRC}/objs/ngx_http_headers_more_filter_module.so \
	    ${STAGEDIR}${MODDIR}

	${INSTALL_MAN} ${WRKSRC_module}/README.markdown ${STAGEDIR}${DOCSDIR}

do-install-DEBUG-on:
	${INSTALL} ${COPY} -m ${_SHAREMODE} \
	    ${WRKSRC_DEBUG}/objs/ngx_http_headers_more_filter_module.so \
	    ${STAGEDIR}${MODDIR}/ngx_http_headers_more_filter_module-debug.so

.include "${MASTERDIR}/Makefile"
