PORTNAME=	angie-module-cache-purge
MODULE_VERSION= 2.5.4
MODULE_PORTREVISION=	0
GH_TUPLE=	nginx-modules:ngx_cache_purge:${MODULE_VERSION}:module

COMMENT=	Angie cache_purge dynamic module
WWW=		https://github.com/nginx-modules/ngx_cache_purge/

MASTERDIR=	${.CURDIR}/../../www/angie

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR} \
		 ${STAGEDIR}${MODDIR}

	${INSTALL_LIB} ${WRKSRC}/objs/ngx_http_cache_purge_module.so \
	    ${STAGEDIR}${MODDIR}

	${INSTALL_MAN} ${WRKSRC_module}/README.md ${STAGEDIR}${DOCSDIR}

do-install-DEBUG-on:
	${INSTALL} ${COPY} -m ${_SHAREMODE} \
	    ${WRKSRC_DEBUG}/objs/ngx_http_cache_purge_module.so \
	    ${STAGEDIR}${MODDIR}/ngx_http_cache_purge_module-debug.so

.include "${MASTERDIR}/Makefile"
