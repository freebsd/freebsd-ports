PORTNAME=	nginx-module-dynamic-upstream
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4.1
CATEGORIES=	www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Sources of the dynamic_upstream module for the NGINX ports
WWW=		https://github.com/sysadmin-labs/nginx-dynamic-upstream-module

LICENSE=	MIT BSD2CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE
LICENSE_FILE_BSD2CLAUSE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	sysadmin-labs
GH_PROJECT=	nginx-dynamic-upstream-module

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

_MODDIR=	share/nginx/modules/${PORTNAME}
MODULESDIR=	${PREFIX}/${_MODDIR}

PLIST_FILES=	${_MODDIR}/config \
		${_MODDIR}/src/ngx_dynamic_upstream_module.h \
		${_MODDIR}/src/ngx_dynamic_upstream_op.cpp \
		${_MODDIR}/src/ngx_dynamic_upstream_op.h \
		${_MODDIR}/src/ngx_http_dynamic_upstream_module.cpp

do-install:
	@${MKDIR} ${STAGEDIR}${MODULESDIR}/src
	${INSTALL_DATA} ${WRKSRC}/config ${STAGEDIR}${MODULESDIR}
	${INSTALL_DATA} ${WRKSRC}/src/ngx_dynamic_upstream_module.h \
		${WRKSRC}/src/ngx_dynamic_upstream_op.cpp \
		${WRKSRC}/src/ngx_dynamic_upstream_op.h \
		${WRKSRC}/src/ngx_http_dynamic_upstream_module.cpp \
		${STAGEDIR}${MODULESDIR}/src

.include <bsd.port.mk>
