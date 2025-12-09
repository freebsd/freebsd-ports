PORTNAME=	angie-module-enhanced-memcached
MODULE_VERSION=	0.3
MODULE_PORTREVISION=	0
GH_TUPLE=	bpaquet:ngx_http_enhanced_memcached_module:v${MODULE_VERSION}:module

COMMENT=	Angie enhanced memcached dynamic module
WWW=		https://github.com/bpaquet/ngx_http_enhanced_memcached_module/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC_module}/README.markdown

MASTERDIR=	${.CURDIR}/../../www/angie

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR} \
		 ${STAGEDIR}${MODDIR}

	${INSTALL_LIB} ${WRKSRC}/objs/ngx_http_enhanced_memcached_module.so \
	    ${STAGEDIR}${MODDIR}

	${INSTALL_MAN} ${WRKSRC_module}/README.markdown ${STAGEDIR}${DOCSDIR}

do-install-DEBUG-on:
	${INSTALL} ${COPY} -m ${_SHAREMODE} \
	    ${WRKSRC_DEBUG}/objs/ngx_http_enhanced_memcached_module.so \
	    ${STAGEDIR}${MODDIR}/ngx_http_enhanced_memcached_module-debug.so

.include "${MASTERDIR}/Makefile"
