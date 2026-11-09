PORTNAME=	nginx-module-brotli
DISTVERSION=	1.0.0rc.20231009
CATEGORIES=	www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Sources of the brotli module for the NGINX ports
WWW=		https://github.com/google/ngx_brotli

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	google
GH_PROJECT=	ngx_brotli
GH_TAGNAME=	a71f931

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

_MODDIR=	share/nginx/modules/${PORTNAME}
MODULESDIR=	${PREFIX}/${_MODDIR}

PLIST_FILES=	${_MODDIR}/config \
		${_MODDIR}/filter/config \
		${_MODDIR}/filter/ngx_http_brotli_filter_module.c \
		${_MODDIR}/static/config \
		${_MODDIR}/static/ngx_http_brotli_static_module.c

post-patch:
	@${REINPLACE_CMD} 's!%%PREFIX%%!${LOCALBASE}!g' ${WRKSRC}/filter/config

do-install:
	@${MKDIR} ${STAGEDIR}${MODULESDIR}/filter ${STAGEDIR}${MODULESDIR}/static
	${INSTALL_DATA} ${WRKSRC}/config ${STAGEDIR}${MODULESDIR}
	${INSTALL_DATA} ${WRKSRC}/filter/config \
		${WRKSRC}/filter/ngx_http_brotli_filter_module.c \
		${STAGEDIR}${MODULESDIR}/filter
	${INSTALL_DATA} ${WRKSRC}/static/config \
		${WRKSRC}/static/ngx_http_brotli_static_module.c \
		${STAGEDIR}${MODULESDIR}/static

.include <bsd.port.mk>
