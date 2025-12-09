PORTNAME=	angie-module-echo
MODULE_VERSION=	0.63
MODULE_PORTREVISION=	0
GH_TUPLE=	openresty:echo-nginx-module:v${MODULE_VERSION}:module

COMMENT=	Angie echo dynamic module
WWW=		https://github.com/openresty/echo-nginx-module/

MASTERDIR=	${.CURDIR}/../../www/angie

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR} \
		 ${STAGEDIR}${MODDIR}

	${INSTALL_LIB} ${WRKSRC}/objs/ngx_http_echo_module.so \
	    ${STAGEDIR}${MODDIR}

	${INSTALL_MAN} ${WRKSRC_module}/README.markdown ${STAGEDIR}${DOCSDIR}

do-install-DEBUG-on:
	${INSTALL} ${COPY} -m ${_SHAREMODE} \
	    ${WRKSRC_DEBUG}/objs/ngx_http_echo_module.so \
	    ${STAGEDIR}${MODDIR}/ngx_http_echo_module-debug.so

.include "${MASTERDIR}/Makefile"
