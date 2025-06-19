PORTNAME=	angie-module-auth-spnego
GH_TUPLE=	stnoonan:spnego-http-auth-nginx-module:v1.1.3:module

COMMENT=	Angie auth-spnego dynamic module

USES=		gssapi

MASTERDIR=	${.CURDIR}/../../www/angie

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${MODDIR}

	${INSTALL_LIB} ${WRKSRC}/objs/ngx_http_auth_spnego_module.so \
	    ${STAGEDIR}${MODDIR}

	${INSTALL_MAN} ${WRKSRC_module}/README.md ${STAGEDIR}${DOCSDIR}

do-install-DEBUG-on:
	${INSTALL} ${COPY} -m ${_SHAREMODE} \
	    ${WRKSRC_DEBUG}/objs/ngx_http_auth_spnego_module.so \
	    ${STAGEDIR}${MODDIR}/ngx_http_auth_spnego_module-debug.so

.include "${MASTERDIR}/Makefile"
