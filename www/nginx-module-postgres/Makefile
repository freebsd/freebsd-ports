PORTNAME=	nginx-module-postgres
DISTVERSION=	1.0.0
CATEGORIES=	www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Sources of the postgres module for the NGINX ports
WWW=		https://github.com/sysadmin-labs/nginx-postgres-module

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	sysadmin-labs
GH_PROJECT=	nginx-postgres-module

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

_MODDIR=	share/nginx/modules/${PORTNAME}
MODULESDIR=	${PREFIX}/${_MODDIR}

_MODFILES=	src/ngx_postgres_ddebug.h \
		src/ngx_postgres_escape.c \
		src/ngx_postgres_escape.h \
		src/ngx_postgres_handler.c \
		src/ngx_postgres_handler.h \
		src/ngx_postgres_keepalive.c \
		src/ngx_postgres_keepalive.h \
		src/ngx_postgres_module.c \
		src/ngx_postgres_module.h \
		src/ngx_postgres_output.c \
		src/ngx_postgres_output.h \
		src/ngx_postgres_processor.c \
		src/ngx_postgres_processor.h \
		src/ngx_postgres_rewrite.c \
		src/ngx_postgres_rewrite.h \
		src/ngx_postgres_upstream.c \
		src/ngx_postgres_upstream.h \
		src/ngx_postgres_util.c \
		src/ngx_postgres_util.h \
		src/ngx_postgres_variable.c \
		src/ngx_postgres_variable.h \
		src/resty_dbd_stream.h

PLIST_FILES=	${_MODDIR}/config \
		${_MODFILES:S!^!${_MODDIR}/!}

do-install:
	@${MKDIR} ${STAGEDIR}${MODULESDIR}/src
	${INSTALL_DATA} ${WRKSRC}/config ${STAGEDIR}${MODULESDIR}
	${INSTALL_DATA} ${_MODFILES:S!^!${WRKSRC}/!} ${STAGEDIR}${MODULESDIR}/src

.include <bsd.port.mk>
