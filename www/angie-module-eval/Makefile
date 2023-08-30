PORTNAME=	angie-module-eval
GH_TUPLE=	openresty:nginx-eval-module:2016.06.10:module

COMMENT=	Angie eval dynamic module

LICENSE_FILE=	${WRKSRC_module}/LICENCE

MASTERDIR=	${.CURDIR}/../../www/angie

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${MODDIR}

	${INSTALL_LIB} ${WRKSRC}/objs/ngx_http_eval_module.so \
	    ${STAGEDIR}${MODDIR}

	${INSTALL_MAN} ${WRKSRC_module}/README.md ${STAGEDIR}${DOCSDIR}

do-install-DEBUG-on:
	${INSTALL} ${COPY} -m ${_SHAREMODE} \
	    ${WRKSRC_DEBUG}/objs/ngx_http_eval_module.so \
	    ${STAGEDIR}${MODDIR}/ngx_http_eval_module-debug.so

.include "${MASTERDIR}/Makefile"
