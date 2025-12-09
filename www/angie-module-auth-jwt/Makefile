PORTNAME=	angie-module-auth-jwt
MODULE_VERSION=	0.9.0
MODULE_PORTREVISION=	0
GH_TUPLE=	kjdev:nginx-auth-jwt:${MODULE_VERSION}:module

COMMENT=	Angie auth-jwt dynamic module
WWW=		https://github.com/kjdev/nginx-auth-jwt/

LICENSE=	MIT

LIB_DEPENDS=	libjansson.so:devel/jansson

MASTERDIR=	${.CURDIR}/../../www/angie

CONFLICTS=	www/angie-module-jwt

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR} \
		 ${STAGEDIR}${MODDIR}

	${INSTALL_LIB} ${WRKSRC}/objs/ngx_http_auth_jwt_module.so \
	    ${STAGEDIR}${MODDIR}

	${INSTALL_MAN} ${WRKSRC_module}/README.md ${STAGEDIR}${DOCSDIR}

do-install-DEBUG-on:
	${INSTALL} ${COPY} -m ${_SHAREMODE} \
	    ${WRKSRC_DEBUG}/objs/ngx_http_auth_jwt_module.so \
	    ${STAGEDIR}${MODDIR}/ngx_http_auth_jwt_module-debug.so

.include "${MASTERDIR}/Makefile"
