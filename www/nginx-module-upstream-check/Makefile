PORTNAME=	nginx-module-upstream-check
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.1
CATEGORIES=	www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Sources of the upstream_check module for the NGINX ports
WWW=		https://github.com/sysadmin-labs/nginx-upstream-check-module

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	sysadmin-labs
GH_PROJECT=	nginx-upstream-check-module

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

_MODDIR=	share/nginx/modules/${PORTNAME}
MODULESDIR=	${PREFIX}/${_MODDIR}

PLIST_FILES=	${_MODDIR}/config \
		${_MODDIR}/patches/freenginx-1.30+.patch \
		${_MODDIR}/patches/nginx-1.30+.patch \
		${_MODDIR}/src/ngx_http_upstream_check_module.c \
		${_MODDIR}/src/ngx_http_upstream_check_module.h

do-install:
	@${MKDIR} ${STAGEDIR}${MODULESDIR}/src \
		${STAGEDIR}${MODULESDIR}/patches
	${INSTALL_DATA} ${WRKSRC}/config ${STAGEDIR}${MODULESDIR}
	${INSTALL_DATA} ${WRKSRC}/patches/freenginx-1.30+.patch \
		${WRKSRC}/patches/nginx-1.30+.patch \
		${STAGEDIR}${MODULESDIR}/patches
	${INSTALL_DATA} ${WRKSRC}/src/ngx_http_upstream_check_module.c \
		${WRKSRC}/src/ngx_http_upstream_check_module.h \
		${STAGEDIR}${MODULESDIR}/src

.include <bsd.port.mk>
