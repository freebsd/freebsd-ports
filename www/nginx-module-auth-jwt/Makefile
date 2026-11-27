PORTNAME=	nginx-module-auth-jwt
DISTVERSION=	2.5.2
CATEGORIES=	www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Sources of the auth_jwt module for the NGINX ports
WWW=		https://github.com/TeslaGov/ngx-http-auth-jwt-module

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	TeslaGov
GH_PROJECT=	ngx-http-auth-jwt-module

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

_MODDIR=	share/nginx/modules/${PORTNAME}
MODULESDIR=	${PREFIX}/${_MODDIR}

_MODSRC=	src LICENSE

do-install:
	@${MKDIR} ${STAGEDIR}${MODULESDIR}
	${INSTALL_DATA} ${WRKSRC}/config ${STAGEDIR}${MODULESDIR}
	@cd ${WRKSRC} && \
		${COPYTREE_SHARE} "${_MODSRC}" ${STAGEDIR}${MODULESDIR}

.include <bsd.port.mk>
