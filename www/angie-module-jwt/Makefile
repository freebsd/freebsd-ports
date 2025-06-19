PORTNAME=	angie-module-jwt
GH_TUPLE=	max-lt:nginx-jwt-module:v3.4.3:module

COMMENT=	Angie JWT dynamic module

LIB_DEPENDS=	libjansson.so:devel/jansson \
		libjwt.so:www/libjwt

MASTERDIR=	${.CURDIR}/../../www/angie

CONFLICTS=	www/angie-module-auth-jwt

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
