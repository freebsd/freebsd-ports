PORTNAME=	nginx-module-modsecurity3
DISTVERSION=	1.0.4.20260926
CATEGORIES=	www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Sources of the modsecurity3 module for the NGINX ports
WWW=		https://github.com/owasp-modsecurity/ModSecurity-nginx

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	owasp-modsecurity
GH_PROJECT=	ModSecurity-nginx
GH_TAGNAME=	b7cf44e

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

_MODDIR=	share/nginx/modules/${PORTNAME}
MODULESDIR=	${PREFIX}/${_MODDIR}

PLIST_FILES=	${_MODDIR}/config \
		${_MODDIR}/src/ddebug.h \
		${_MODDIR}/src/ngx_http_modsecurity_access.c \
		${_MODDIR}/src/ngx_http_modsecurity_body_filter.c \
		${_MODDIR}/src/ngx_http_modsecurity_common.h \
		${_MODDIR}/src/ngx_http_modsecurity_header_filter.c \
		${_MODDIR}/src/ngx_http_modsecurity_log.c \
		${_MODDIR}/src/ngx_http_modsecurity_module.c

do-install:
	@${MKDIR} ${STAGEDIR}${MODULESDIR} ${STAGEDIR}${MODULESDIR}/src
	${INSTALL_DATA} ${WRKSRC}/config ${STAGEDIR}${MODULESDIR}
	${INSTALL_DATA} ${WRKSRC}/src/ddebug.h \
		${WRKSRC}/src/ngx_http_modsecurity_access.c \
		${WRKSRC}/src/ngx_http_modsecurity_body_filter.c \
		${WRKSRC}/src/ngx_http_modsecurity_common.h \
		${WRKSRC}/src/ngx_http_modsecurity_header_filter.c \
		${WRKSRC}/src/ngx_http_modsecurity_log.c \
		${WRKSRC}/src/ngx_http_modsecurity_module.c \
		${STAGEDIR}${MODULESDIR}/src

.include <bsd.port.mk>
