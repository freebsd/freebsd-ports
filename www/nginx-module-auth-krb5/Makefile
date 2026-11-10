PORTNAME=	nginx-module-auth-krb5
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.3
CATEGORIES=	www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Sources of the auth_krb5 module for the NGINX ports
WWW=		https://github.com/stnoonan/spnego-http-auth-nginx-module

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	stnoonan
GH_PROJECT=	spnego-http-auth-nginx-module

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

_MODDIR=	share/nginx/modules/${PORTNAME}
MODULESDIR=	${PREFIX}/${_MODDIR}

PLIST_FILES=	${_MODDIR}/config \
		${_MODDIR}/ngx_http_auth_spnego_module.c

do-install:
	@${MKDIR} ${STAGEDIR}${MODULESDIR}
	${INSTALL_DATA} ${WRKSRC}/config \
		${WRKSRC}/ngx_http_auth_spnego_module.c \
		${STAGEDIR}${MODULESDIR}

.include <bsd.port.mk>
