PORTNAME=	nginx-module-ajp
DISTVERSION=	0.3.0.20210820
CATEGORIES=	www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Sources of the AJP module for the NGINX ports
WWW=		https://github.com/msva/nginx_ajp_module

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	msva
GH_PROJECT=	nginx_ajp_module
GH_TAGNAME=	fcbb2cc

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

_MODDIR=	share/nginx/modules/${PORTNAME}
MODULESDIR=	${PREFIX}/${_MODDIR}

PLIST_FILES=	${_MODDIR}/config \
		${_MODDIR}/ngx_http_ajp.c \
		${_MODDIR}/ngx_http_ajp.h \
		${_MODDIR}/ngx_http_ajp_handler.c \
		${_MODDIR}/ngx_http_ajp_handler.h \
		${_MODDIR}/ngx_http_ajp_module.c \
		${_MODDIR}/ngx_http_ajp_module.h \
		${_MODDIR}/ngx_http_ajp_msg.c

do-install:
	@${MKDIR} ${STAGEDIR}${MODULESDIR}
	${INSTALL_DATA} ${WRKSRC}/config \
		${WRKSRC}/ngx_http_ajp.c \
		${WRKSRC}/ngx_http_ajp.h \
		${WRKSRC}/ngx_http_ajp_handler.c \
		${WRKSRC}/ngx_http_ajp_handler.h \
		${WRKSRC}/ngx_http_ajp_module.c \
		${WRKSRC}/ngx_http_ajp_module.h \
		${WRKSRC}/ngx_http_ajp_msg.c \
		${STAGEDIR}${MODULESDIR}

.include <bsd.port.mk>
