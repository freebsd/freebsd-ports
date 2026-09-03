PORTNAME=	nginx-module-njs
DISTVERSION=	1.0.1
CATEGORIES=	www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Sources of the njs (JavaScript) module for the NGINX ports
WWW=		https://nginx.org/en/docs/njs/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe
CPE_VENDOR=	f5
CPE_PRODUCT=	njs

USE_GITHUB=	yes
GH_ACCOUNT=	nginx
GH_PROJECT=	njs

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

MODULESDIR=	${PREFIX}/share/nginx/modules/${PORTNAME}

_MODSRC=	auto external nginx src ts test/ts LICENSE

do-install:
	@${MKDIR} ${STAGEDIR}${MODULESDIR}
	${INSTALL_DATA} ${WRKSRC}/configure ${STAGEDIR}${MODULESDIR}
	@cd ${WRKSRC} && \
		${COPYTREE_SHARE} "${_MODSRC}" ${STAGEDIR}${MODULESDIR}
	@${RM} -rf ${STAGEDIR}${MODULESDIR}/nginx/t

.include <bsd.port.mk>
