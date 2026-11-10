PORTNAME=	nginx-module-ip2location
DISTVERSION=	8.7.0
CATEGORIES=	www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Sources of the ip2location module for the NGINX ports
WWW=		https://github.com/ip2location/ip2location-nginx

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	ip2location
GH_PROJECT=	ip2location-nginx

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

_MODDIR=	share/nginx/modules/${PORTNAME}
MODULESDIR=	${PREFIX}/${_MODDIR}

PLIST_FILES=	${_MODDIR}/config \
		${_MODDIR}/ngx_http_ip2location_module.c

do-install:
	@${MKDIR} ${STAGEDIR}${MODULESDIR}
	${INSTALL_DATA} ${WRKSRC}/config \
		${WRKSRC}/ngx_http_ip2location_module.c \
		${STAGEDIR}${MODULESDIR}

.include <bsd.port.mk>
