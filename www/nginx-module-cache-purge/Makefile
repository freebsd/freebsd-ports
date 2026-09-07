PORTNAME=	nginx-module-cache-purge
DISTVERSION=	3.0.2
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Sources of the cache_purge module for the NGINX ports
WWW=		https://github.com/nginx-modules/ngx_cache_purge

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	nginx-modules
GH_PROJECT=	ngx_cache_purge

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

_MODDIR=	share/nginx/modules/${PORTNAME}
MODULESDIR=	${PREFIX}/${_MODDIR}

PLIST_FILES=	${_MODDIR}/config \
		${_MODDIR}/ngx_cache_purge_module.c

do-install:
	@${MKDIR} ${STAGEDIR}${MODULESDIR}
	${INSTALL_DATA} ${WRKSRC}/config \
		${WRKSRC}/ngx_cache_purge_module.c \
		${STAGEDIR}${MODULESDIR}

.include <bsd.port.mk>
