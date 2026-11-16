PORTNAME=	nginx-module-tarantool
DISTVERSIONPREFIX=	v
DISTVERSION=	2.8.1
CATEGORIES=	www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Sources of the tarantool module for the NGINX ports
WWW=		https://github.com/sysadmin-labs/nginx-tarantool-module

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	sysadmin-labs
GH_PROJECT=	nginx-tarantool-module

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

_MODDIR=	share/nginx/modules/${PORTNAME}
MODULESDIR=	${PREFIX}/${_MODDIR}

_MODFILES=	src/debug.h \
		src/json_encoders.c \
		src/json_encoders.h \
		src/ngx_http_tnt_module.c \
		src/ngx_http_tnt_version.h \
		src/tp.h \
		src/tp_ext.h \
		src/tp_transcode.c \
		src/tp_transcode.h

PLIST_FILES=	${_MODDIR}/config \
		${_MODFILES:S!^!${_MODDIR}/!}

do-install:
	@${MKDIR} ${STAGEDIR}${MODULESDIR}/src
	${INSTALL_DATA} ${WRKSRC}/config ${STAGEDIR}${MODULESDIR}
	${INSTALL_DATA} ${_MODFILES:S!^!${WRKSRC}/!} \
		${STAGEDIR}${MODULESDIR}/src

.include <bsd.port.mk>
