PORTNAME=	nginx-module-link
DISTVERSIONPREFIX=	v
DISTVERSION=	3.2.5
CATEGORIES=	www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Sources of the link function module for the NGINX ports
WWW=		https://github.com/sysadmin-labs/nginx-link-function-module

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	sysadmin-labs
GH_PROJECT=	nginx-link-function-module

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

_MODDIR=	share/nginx/modules/${PORTNAME}
MODULESDIR=	${PREFIX}/${_MODDIR}

_MODFILES=	src/ngx_link_func_module.c src/ngx_link_func_module.h

PLIST_FILES=	${_MODDIR}/config \
		${_MODFILES:S,^,${_MODDIR}/,}

do-install:
	@${MKDIR} ${STAGEDIR}${MODULESDIR}/src
	${INSTALL_DATA} ${WRKSRC}/config ${STAGEDIR}${MODULESDIR}
	${INSTALL_DATA} ${_MODFILES:S,^,${WRKSRC}/,} ${STAGEDIR}${MODULESDIR}/src

.include <bsd.port.mk>
