PORTNAME=	nginx-module-zip
DISTVERSION=	1.3.0.20261109
CATEGORIES=	www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Sources of the zip module for the NGINX ports
WWW=		https://github.com/evanmiller/mod_zip

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	evanmiller
GH_PROJECT=	mod_zip
GH_TAGNAME=	a17f1c1

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

_MODDIR=	share/nginx/modules/${PORTNAME}
MODULESDIR=	${PREFIX}/${_MODDIR}

_MODFILES=	ngx_http_zip_endian.h \
		ngx_http_zip_file.c \
		ngx_http_zip_file.h \
		ngx_http_zip_file_format.h \
		ngx_http_zip_headers.c \
		ngx_http_zip_headers.h \
		ngx_http_zip_module.c \
		ngx_http_zip_module.h \
		ngx_http_zip_parsers.c \
		ngx_http_zip_parsers.h

PLIST_FILES=	${_MODDIR}/config \
		${_MODFILES:S!^!${_MODDIR}/!}

do-install:
	@${MKDIR} ${STAGEDIR}${MODULESDIR}
	${INSTALL_DATA} ${WRKSRC}/config ${STAGEDIR}${MODULESDIR}
	${INSTALL_DATA} ${_MODFILES:S!^!${WRKSRC}/!} ${STAGEDIR}${MODULESDIR}

.include <bsd.port.mk>
