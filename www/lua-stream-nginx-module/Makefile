PORTNAME=	lua-stream-nginx-module
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.17
CATEGORIES=	www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Lua module for the NGINX stream subsystem
WWW=		https://github.com/openresty/stream-lua-nginx-module

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	openresty
GH_PROJECT=	stream-lua-nginx-module

NO_ARCH=	yes
NO_BUILD=	yes

MODULESDIR=	${LOCALBASE}/share/nginx/modules/${PORTNAME}

PLIST_SUB=	MODULESDIR=${MODULESDIR}

do-install:
	@${MKDIR} ${STAGEDIR}${MODULESDIR}/src
	${INSTALL_DATA} ${WRKSRC}/config ${STAGEDIR}${MODULESDIR}
	@cd ${WRKSRC}/src && \
		${COPYTREE_SHARE} . ${STAGEDIR}${MODULESDIR}/src

.include <bsd.port.mk>
