PORTNAME=	nginx-module-websockify
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.4
CATEGORIES=	www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Sources of the websockify module for the NGINX ports
WWW=		https://github.com/sysadmin-labs/nginx-websockify-module

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	sysadmin-labs
GH_PROJECT=	nginx-websockify-module

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

_MODDIR=	share/nginx/modules/${PORTNAME}
MODULESDIR=	${PREFIX}/${_MODDIR}

PLIST_FILES=	${_MODDIR}/config \
		${_MODDIR}/src/ngx_http_websockify_module.c \
		${_MODDIR}/src/websocket.h

do-install:
	@${MKDIR} ${STAGEDIR}${MODULESDIR}/src
	${INSTALL_DATA} ${WRKSRC}/config ${STAGEDIR}${MODULESDIR}
	${INSTALL_DATA} ${WRKSRC}/src/ngx_http_websockify_module.c \
		${WRKSRC}/src/websocket.h \
		${STAGEDIR}${MODULESDIR}/src

.include <bsd.port.mk>
