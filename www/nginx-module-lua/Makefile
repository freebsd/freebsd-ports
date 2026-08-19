PORTNAME=	nginx-module-lua
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.29
PORTREVISION=	3
CATEGORIES=	www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Lua module for the NGINX HTTP subsystem
WWW=		https://github.com/openresty/lua-nginx-module

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	openresty
GH_PROJECT=	lua-nginx-module

NO_ARCH=	yes
NO_BUILD=	yes

MODULESDIR=	${LOCALBASE}/share/nginx/modules/${PORTNAME}

do-install:
	@${MKDIR} ${STAGEDIR}${MODULESDIR}/src
	${INSTALL_DATA} ${WRKSRC}/config ${STAGEDIR}${MODULESDIR}
	@cd ${WRKSRC}/src && \
		${COPYTREE_SHARE} . ${STAGEDIR}${MODULESDIR}/src

.include <bsd.port.mk>
