PORTNAME=	nginx-module-ndk
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.4
CATEGORIES=	www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Nginx Development Kit module
WWW=		https://github.com/vision5/ngx_devel_kit

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	vision5
GH_PROJECT=	ngx_devel_kit

NO_ARCH=	yes
NO_BUILD=	yes

MODULESDIR=	${LOCALBASE}/share/nginx/modules/${PORTNAME}

do-install:
	@${MKDIR} ${STAGEDIR}${MODULESDIR}
	${INSTALL_DATA} ${WRKSRC}/config ${WRKSRC}/ngx_auto_lib_core \
		${STAGEDIR}${MODULESDIR}
	@cd ${WRKSRC} && \
		${COPYTREE_SHARE} "objs src" ${STAGEDIR}${MODULESDIR}

.include <bsd.port.mk>
