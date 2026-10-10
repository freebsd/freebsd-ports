PORTNAME=	nginx-module-zstd
DISTVERSION=	0.1.3
CATEGORIES=	www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Sources of the zstd modules for the NGINX ports
WWW=		https://github.com/sysadmin-labs/nginx-zstd-module

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	sysadmin-labs
GH_PROJECT=	nginx-zstd-module

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

_MODDIR=	share/nginx/modules/${PORTNAME}
MODULESDIR=	${PREFIX}/${_MODDIR}

PLIST_FILES=	${_MODDIR}/config \
		${_MODDIR}/filter/config \
		${_MODDIR}/src/ngx_http_zstd_filter_module.c \
		${_MODDIR}/src/ngx_http_zstd_static_module.c \
		${_MODDIR}/static/config

do-install:
	@${MKDIR} ${STAGEDIR}${MODULESDIR}/filter \
		${STAGEDIR}${MODULESDIR}/src \
		${STAGEDIR}${MODULESDIR}/static
	${INSTALL_DATA} ${WRKSRC}/config ${STAGEDIR}${MODULESDIR}
	${INSTALL_DATA} ${WRKSRC}/filter/config ${STAGEDIR}${MODULESDIR}/filter
	${INSTALL_DATA} ${WRKSRC}/static/config ${STAGEDIR}${MODULESDIR}/static
	${INSTALL_DATA} ${WRKSRC}/src/ngx_http_zstd_filter_module.c \
		${WRKSRC}/src/ngx_http_zstd_static_module.c \
		${STAGEDIR}${MODULESDIR}/src

.include <bsd.port.mk>
