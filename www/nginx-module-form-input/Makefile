PORTNAME=	nginx-module-form-input
DISTVERSIONPREFIX=	v
DISTVERSION=	0.12
CATEGORIES=	www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Sources of the form_input module for the NGINX ports
WWW=		https://github.com/calio/form-input-nginx-module

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/README.md

USE_GITHUB=	yes
GH_ACCOUNT=	calio
GH_PROJECT=	form-input-nginx-module

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

_MODDIR=	share/nginx/modules/${PORTNAME}
MODULESDIR=	${PREFIX}/${_MODDIR}

PLIST_FILES=	${_MODDIR}/config \
		${_MODDIR}/src/ddebug.h \
		${_MODDIR}/src/ngx_http_form_input_module.c

do-install:
	@${MKDIR} ${STAGEDIR}${MODULESDIR}/src
	${INSTALL_DATA} ${WRKSRC}/config ${STAGEDIR}${MODULESDIR}
	${INSTALL_DATA} ${WRKSRC}/src/ddebug.h \
		${WRKSRC}/src/ngx_http_form_input_module.c \
		${STAGEDIR}${MODULESDIR}/src

.include <bsd.port.mk>
