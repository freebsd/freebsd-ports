PORTNAME=	nginx-module-accept-language
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0
CATEGORIES=	www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Sources of the accept_language module for the NGINX ports
WWW=		https://github.com/sysadmin-labs/nginx-accept-language-module

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	sysadmin-labs
GH_PROJECT=	nginx-accept-language-module

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

_MODDIR=	share/nginx/modules/${PORTNAME}
MODULESDIR=	${PREFIX}/${_MODDIR}

PLIST_FILES=	${_MODDIR}/config \
		${_MODDIR}/src/ngx_http_accept_language_module.c

do-install:
	@${MKDIR} ${STAGEDIR}${MODULESDIR} ${STAGEDIR}${MODULESDIR}/src
	${INSTALL_DATA} ${WRKSRC}/config ${STAGEDIR}${MODULESDIR}
	${INSTALL_DATA} ${WRKSRC}/src/ngx_http_accept_language_module.c \
		${STAGEDIR}${MODULESDIR}/src

.include <bsd.port.mk>
