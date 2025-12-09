PORTNAME=	angie-module-keyval
MODULE_VERSION=	0.3.0
MODULE_PORTREVISION=	0
GH_TUPLE=	kjdev:nginx-keyval:${MODULE_VERSION}:module

COMMENT=	Angie keyval dynamic module
WWW=		https://github.com/kjdev/nginx-keyval/

LICENSE=	MIT

LIB_DEPENDS=	libhiredis.so:databases/hiredis

MASTERDIR=	${.CURDIR}/../../www/angie

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR} \
		 ${STAGEDIR}${MODDIR}

	${INSTALL_LIB} ${WRKSRC}/objs/ngx_http_keyval_module.so \
	    ${STAGEDIR}${MODDIR}

	${INSTALL_MAN} ${WRKSRC_module}/README.md ${STAGEDIR}${DOCSDIR}

do-install-DEBUG-on:
	${INSTALL} ${COPY} -m ${_SHAREMODE} \
	    ${WRKSRC_DEBUG}/objs/ngx_http_keyval_module.so \
	    ${STAGEDIR}${MODDIR}/ngx_http_keyval_module-debug.so

.include "${MASTERDIR}/Makefile"
