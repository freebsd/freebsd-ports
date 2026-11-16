PORTNAME=	nginx-module-ajp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.2
CATEGORIES=	www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Sources of the AJP module for the NGINX ports
WWW=		https://github.com/sysadmin-labs/nginx-ajp-module

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	sysadmin-labs
GH_PROJECT=	nginx-ajp-module

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

_MODDIR=	share/nginx/modules/${PORTNAME}
MODULESDIR=	${PREFIX}/${_MODDIR}

_MODFILES=	src/ngx_http_ajp.c \
		src/ngx_http_ajp.h \
		src/ngx_http_ajp_handler.c \
		src/ngx_http_ajp_handler.h \
		src/ngx_http_ajp_module.c \
		src/ngx_http_ajp_module.h \
		src/ngx_http_ajp_msg.c

PLIST_FILES=	${_MODDIR}/config \
		${_MODFILES:S!^!${_MODDIR}/!}

do-install:
	@${MKDIR} ${STAGEDIR}${MODULESDIR}/src
	${INSTALL_DATA} ${WRKSRC}/config ${STAGEDIR}${MODULESDIR}
	${INSTALL_DATA} ${_MODFILES:S!^!${WRKSRC}/!} \
		${STAGEDIR}${MODULESDIR}/src

.include <bsd.port.mk>
