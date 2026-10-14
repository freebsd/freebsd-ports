PORTNAME=	nginx-module-fips-check
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2
CATEGORIES=	www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Sources of the fips_check module for the NGINX ports
WWW=		https://github.com/sysadmin-labs/nginx-fips-check-module

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	sysadmin-labs
GH_PROJECT=	nginx-fips-check-module

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

_MODDIR=	share/nginx/modules/${PORTNAME}
MODULESDIR=	${PREFIX}/${_MODDIR}

PLIST_FILES=	${_MODDIR}/config \
		${_MODDIR}/NOTICE \
		${_MODDIR}/src/ngx_core_fips_check_module.c

do-install:
	@${MKDIR} ${STAGEDIR}${MODULESDIR} ${STAGEDIR}${MODULESDIR}/src
	${INSTALL_DATA} ${WRKSRC}/config ${STAGEDIR}${MODULESDIR}
	${INSTALL_DATA} ${WRKSRC}/NOTICE \
		${STAGEDIR}${MODULESDIR}
	${INSTALL_DATA} ${WRKSRC}/src/ngx_core_fips_check_module.c \
		${STAGEDIR}${MODULESDIR}/src

.include <bsd.port.mk>
