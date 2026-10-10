PORTNAME=	nginx-module-let
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.6
CATEGORIES=	www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Sources of the let module for the NGINX ports
WWW=		https://github.com/sysadmin-labs/nginx-let-module

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	sysadmin-labs
GH_PROJECT=	nginx-let-module

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

_MODDIR=	share/nginx/modules/${PORTNAME}
MODULESDIR=	${PREFIX}/${_MODDIR}

PLIST_FILES=	${_MODDIR}/config \
		${_MODDIR}/src/let.h \
		${_MODDIR}/src/let.tab.c \
		${_MODDIR}/src/let.tab.h \
		${_MODDIR}/src/ngx_http_let_module.c

do-install:
	@${MKDIR} ${STAGEDIR}${MODULESDIR}/src
	${INSTALL_DATA} ${WRKSRC}/config ${STAGEDIR}${MODULESDIR}
	${INSTALL_DATA} ${WRKSRC}/src/let.h \
		${WRKSRC}/src/let.tab.c \
		${WRKSRC}/src/let.tab.h \
		${WRKSRC}/src/ngx_http_let_module.c \
		${STAGEDIR}${MODULESDIR}/src

.include <bsd.port.mk>
