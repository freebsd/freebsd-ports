PORTNAME=	angie-module-eval
MODULE_VERSION=	2016.06.10
MODULE_PORTREVISION=	0
GH_TUPLE=	openresty:nginx-eval-module:${MODULE_VERSION}:module

COMMENT=	Angie eval dynamic module
WWW=		https://github.com/openresty/nginx-eval-module/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC_module}/LICENCE

MASTERDIR=	${.CURDIR}/../../www/angie

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR} \
		 ${STAGEDIR}${MODDIR}

	${INSTALL_LIB} ${WRKSRC}/objs/ngx_http_eval_module.so \
	    ${STAGEDIR}${MODDIR}

	${INSTALL_MAN} ${WRKSRC_module}/README.md ${STAGEDIR}${DOCSDIR}

do-install-DEBUG-on:
	${INSTALL} ${COPY} -m ${_SHAREMODE} \
	    ${WRKSRC_DEBUG}/objs/ngx_http_eval_module.so \
	    ${STAGEDIR}${MODDIR}/ngx_http_eval_module-debug.so

.include "${MASTERDIR}/Makefile"
