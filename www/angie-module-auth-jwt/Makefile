PORTNAME=	angie-module-auth-jwt
GH_TUPLE=	kjdev:nginx-auth-jwt:0.2.1:module

COMMENT=	Angie auth-jwt dynamic module

LIB_DEPENDS=	libjansson.so:devel/jansson

MASTERDIR=	${.CURDIR}/../../www/angie

CONFLICTS=	www/angie-module-jwt

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${MODDIR}

	${INSTALL_LIB} ${WRKSRC}/objs/ngx_http_auth_jwt_module.so \
	    ${STAGEDIR}${MODDIR}

	${INSTALL_MAN} ${WRKSRC_module}/README.md ${STAGEDIR}${DOCSDIR}

do-install-DEBUG-on:
	${INSTALL} ${COPY} -m ${_SHAREMODE} \
	    ${WRKSRC_DEBUG}/objs/ngx_http_auth_jwt_module.so \
	    ${STAGEDIR}${MODDIR}/ngx_http_auth_jwt_module-debug.so

.include "${MASTERDIR}/Makefile"
