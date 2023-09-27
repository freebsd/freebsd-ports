PORTNAME=	angie-module-keyval
GH_TUPLE=	kjdev:nginx-keyval:0.2.0:module

COMMENT=	Angie keyval dynamic module

LIB_DEPENDS=	libhiredis.so:databases/hiredis

MASTERDIR=	${.CURDIR}/../../www/angie

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${MODDIR}

	${INSTALL_LIB} ${WRKSRC}/objs/ngx_http_keyval_module.so \
	    ${STAGEDIR}${MODDIR}

	${INSTALL_MAN} ${WRKSRC_module}/README.md ${STAGEDIR}${DOCSDIR}

do-install-DEBUG-on:
	${INSTALL} ${COPY} -m ${_SHAREMODE} \
	    ${WRKSRC_DEBUG}/objs/ngx_http_keyval_module.so \
	    ${STAGEDIR}${MODDIR}/ngx_http_keyval_module-debug.so

.include "${MASTERDIR}/Makefile"
