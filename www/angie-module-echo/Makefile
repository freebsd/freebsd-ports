PORTNAME=	angie-module-echo
GH_TUPLE=	openresty:echo-nginx-module:v0.63:module

COMMENT=	Angie echo dynamic module

MASTERDIR=	${.CURDIR}/../../www/angie

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${MODDIR}

	${INSTALL_LIB} ${WRKSRC}/objs/ngx_http_echo_module.so \
	    ${STAGEDIR}${MODDIR}

	${INSTALL_MAN} ${WRKSRC_module}/README.markdown ${STAGEDIR}${DOCSDIR}

do-install-DEBUG-on:
	${INSTALL} ${COPY} -m ${_SHAREMODE} \
	    ${WRKSRC_DEBUG}/objs/ngx_http_echo_module.so \
	    ${STAGEDIR}${MODDIR}/ngx_http_echo_module-debug.so

.include "${MASTERDIR}/Makefile"
