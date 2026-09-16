PORTNAME=	nginx-module-vod
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.2
CATEGORIES=	www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Sources of the vod module for the NGINX ports
WWW=		https://github.com/dio-az/nginx-vod-module

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	dio-az
GH_PROJECT=	nginx-vod-module

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

MODULESDIR=	${PREFIX}/share/nginx/modules/${PORTNAME}

_MODSRC=	*.c *.h vod LICENSE

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/include/libxml2|${LOCALBASE}/include/libxml2|' \
		${WRKSRC}/config

do-install:
	@${MKDIR} ${STAGEDIR}${MODULESDIR}
	${INSTALL_DATA} ${WRKSRC}/config ${STAGEDIR}${MODULESDIR}
	@cd ${WRKSRC} && \
		${COPYTREE_SHARE} "${_MODSRC}" ${STAGEDIR}${MODULESDIR}

.include <bsd.port.mk>
