PORTNAME=	nginx-module-auth-pam
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.5
CATEGORIES=	www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Sources of the auth_pam module for the NGINX ports
WWW=		https://github.com/sto/ngx_http_auth_pam_module

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	sto
GH_PROJECT=	ngx_http_auth_pam_module

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

_MODDIR=	share/nginx/modules/${PORTNAME}
MODULESDIR=	${PREFIX}/${_MODDIR}

_MODFILES=	ngx_http_auth_pam_module.c

PLIST_FILES=	${_MODDIR}/config \
		${_MODFILES:S!^!${_MODDIR}/!}

do-install:
	@${MKDIR} ${STAGEDIR}${MODULESDIR}
	${INSTALL_DATA} ${WRKSRC}/config ${STAGEDIR}${MODULESDIR}
	${INSTALL_DATA} ${_MODFILES:S!^!${WRKSRC}/!} ${STAGEDIR}${MODULESDIR}

.include <bsd.port.mk>
