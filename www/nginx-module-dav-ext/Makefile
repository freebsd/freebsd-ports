PORTNAME=	nginx-module-dav-ext
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.1
CATEGORIES=	www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Sources of the WebDAV ext module for the NGINX ports
WWW=		https://github.com/sysadmin-labs/nginx-dav-ext-module

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	sysadmin-labs
GH_PROJECT=	nginx-dav-ext-module

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

_MODDIR=	share/nginx/modules/${PORTNAME}
MODULESDIR=	${PREFIX}/${_MODDIR}

_MODFILES=	src/ngx_http_dav_ext_module.c

PLIST_FILES=	${_MODDIR}/config \
		${_MODFILES:S,^,${_MODDIR}/,}

do-install:
	@${MKDIR} ${STAGEDIR}${MODULESDIR}/src
	${INSTALL_DATA} ${WRKSRC}/config ${STAGEDIR}${MODULESDIR}
	${INSTALL_DATA} ${_MODFILES:S,^,${WRKSRC}/,} ${STAGEDIR}${MODULESDIR}/src

.include <bsd.port.mk>
