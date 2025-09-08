PORTNAME=	angie-module-auth-totp
GH_TUPLE=	61131:nginx-http-auth-totp:1.1.0:module

COMMENT=	Angie auth-totp dynamic module

MASTERDIR=	${.CURDIR}/../../www/angie

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${MODDIR}

	${INSTALL_LIB} ${WRKSRC}/objs/ngx_http_auth_totp_module.so \
	    ${STAGEDIR}${MODDIR}

	${INSTALL_MAN} ${WRKSRC_module}/README.md ${STAGEDIR}${DOCSDIR}

do-install-DEBUG-on:
	${INSTALL} ${COPY} -m ${_SHAREMODE} \
	    ${WRKSRC_DEBUG}/objs/ngx_http_auth_totp_module.so \
	    ${STAGEDIR}${MODDIR}/ngx_http_auth_totp_module-debug.so

.include "${MASTERDIR}/Makefile"
