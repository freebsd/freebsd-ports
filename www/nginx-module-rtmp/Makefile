PORTNAME=	nginx-module-rtmp
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.1
CATEGORIES=	www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Sources of the RTMP module for the NGINX ports
WWW=		https://github.com/sysadmin-labs/nginx-rtmp-module

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	sysadmin-labs
GH_PROJECT=	nginx-rtmp-module

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

_MODDIR=	share/nginx/modules/${PORTNAME}
MODULESDIR=	${PREFIX}/${_MODDIR}

# Over fifty files in three directories, so the list lives in pkg-plist
# rather than inline.

do-install:
	@${MKDIR} ${STAGEDIR}${MODULESDIR}/src/hls \
		${STAGEDIR}${MODULESDIR}/src/dash
	${INSTALL_DATA} ${WRKSRC}/config ${WRKSRC}/stat.xsl \
		${STAGEDIR}${MODULESDIR}
	${INSTALL_DATA} ${WRKSRC}/src/*.c ${WRKSRC}/src/*.h \
		${STAGEDIR}${MODULESDIR}/src
	${INSTALL_DATA} ${WRKSRC}/src/hls/* ${STAGEDIR}${MODULESDIR}/src/hls
	${INSTALL_DATA} ${WRKSRC}/src/dash/* ${STAGEDIR}${MODULESDIR}/src/dash

.include <bsd.port.mk>
