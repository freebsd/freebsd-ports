PORTNAME=	nginx-module-set-misc
DISTVERSIONPREFIX=	v
DISTVERSION=	0.34
CATEGORIES=	www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Sources of the set_misc module for the NGINX ports
WWW=		https://github.com/openresty/set-misc-nginx-module

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	openresty
GH_PROJECT=	set-misc-nginx-module

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

_MODDIR=	share/nginx/modules/${PORTNAME}
MODULESDIR=	${PREFIX}/${_MODDIR}

PLIST_FILES=	${_MODDIR}/config \
		${_MODDIR}/src/ddebug.h \
		${_MODDIR}/src/ngx_http_set_base32.c \
		${_MODDIR}/src/ngx_http_set_base32.h \
		${_MODDIR}/src/ngx_http_set_base64.c \
		${_MODDIR}/src/ngx_http_set_base64.h \
		${_MODDIR}/src/ngx_http_set_base64url.c \
		${_MODDIR}/src/ngx_http_set_base64url.h \
		${_MODDIR}/src/ngx_http_set_default_value.c \
		${_MODDIR}/src/ngx_http_set_default_value.h \
		${_MODDIR}/src/ngx_http_set_escape_uri.c \
		${_MODDIR}/src/ngx_http_set_escape_uri.h \
		${_MODDIR}/src/ngx_http_set_hash.c \
		${_MODDIR}/src/ngx_http_set_hash.h \
		${_MODDIR}/src/ngx_http_set_hashed_upstream.c \
		${_MODDIR}/src/ngx_http_set_hashed_upstream.h \
		${_MODDIR}/src/ngx_http_set_hex.c \
		${_MODDIR}/src/ngx_http_set_hex.h \
		${_MODDIR}/src/ngx_http_set_hmac.c \
		${_MODDIR}/src/ngx_http_set_hmac.h \
		${_MODDIR}/src/ngx_http_set_local_today.c \
		${_MODDIR}/src/ngx_http_set_local_today.h \
		${_MODDIR}/src/ngx_http_set_misc_module.c \
		${_MODDIR}/src/ngx_http_set_misc_module.h \
		${_MODDIR}/src/ngx_http_set_quote_json.c \
		${_MODDIR}/src/ngx_http_set_quote_json.h \
		${_MODDIR}/src/ngx_http_set_quote_sql.c \
		${_MODDIR}/src/ngx_http_set_quote_sql.h \
		${_MODDIR}/src/ngx_http_set_random.c \
		${_MODDIR}/src/ngx_http_set_random.h \
		${_MODDIR}/src/ngx_http_set_rotate.c \
		${_MODDIR}/src/ngx_http_set_rotate.h \
		${_MODDIR}/src/ngx_http_set_secure_random.c \
		${_MODDIR}/src/ngx_http_set_secure_random.h \
		${_MODDIR}/src/ngx_http_set_unescape_uri.c \
		${_MODDIR}/src/ngx_http_set_unescape_uri.h

do-install:
	@${MKDIR} ${STAGEDIR}${MODULESDIR}/src
	${INSTALL_DATA} ${WRKSRC}/config ${STAGEDIR}${MODULESDIR}
	${INSTALL_DATA} ${WRKSRC}/src/* ${STAGEDIR}${MODULESDIR}/src

.include <bsd.port.mk>
