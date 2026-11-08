PORTNAME=	nginx-module-redis2
DISTVERSIONPREFIX=	v
DISTVERSION=	0.16
CATEGORIES=	www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Sources of the redis2 module for the NGINX ports
WWW=		https://github.com/sysadmin-labs/nginx-redis2-module

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	sysadmin-labs
GH_PROJECT=	nginx-redis2-module

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

_MODDIR=	share/nginx/modules/${PORTNAME}
MODULESDIR=	${PREFIX}/${_MODDIR}

_MODFILES=	src/ddebug.h \
		src/ngx_http_redis2_handler.c \
		src/ngx_http_redis2_handler.h \
		src/ngx_http_redis2_module.c \
		src/ngx_http_redis2_module.h \
		src/ngx_http_redis2_reply.c \
		src/ngx_http_redis2_reply.h \
		src/ngx_http_redis2_util.c \
		src/ngx_http_redis2_util.h

PLIST_FILES=	${_MODDIR}/config \
		${_MODFILES:S!^!${_MODDIR}/!}

do-install:
	@${MKDIR} ${STAGEDIR}${MODULESDIR}/src
	${INSTALL_DATA} ${WRKSRC}/config ${STAGEDIR}${MODULESDIR}
	${INSTALL_DATA} ${_MODFILES:S!^!${WRKSRC}/!} ${STAGEDIR}${MODULESDIR}/src

.include <bsd.port.mk>
