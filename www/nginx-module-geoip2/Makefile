PORTNAME=	nginx-module-geoip2
DISTVERSION=	3.4.20240402
CATEGORIES=	www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Sources of the geoip2 modules for the NGINX ports
WWW=		https://github.com/leev/ngx_http_geoip2_module

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	leev
GH_PROJECT=	ngx_http_geoip2_module
GH_TAGNAME=	445df24

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

_MODDIR=	share/nginx/modules/${PORTNAME}
MODULESDIR=	${PREFIX}/${_MODDIR}

_MODFILES=	ngx_http_geoip2_module.c \
		ngx_stream_geoip2_module.c

PLIST_FILES=	${_MODDIR}/config \
		${_MODFILES:S!^!${_MODDIR}/!}

do-install:
	@${MKDIR} ${STAGEDIR}${MODULESDIR}
	${INSTALL_DATA} ${WRKSRC}/config ${STAGEDIR}${MODULESDIR}
	${INSTALL_DATA} ${_MODFILES:S!^!${WRKSRC}/!} ${STAGEDIR}${MODULESDIR}

.include <bsd.port.mk>
