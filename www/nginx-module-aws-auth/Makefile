PORTNAME=	nginx-module-aws-auth
DISTVERSION=	2.1.1.20260928
CATEGORIES=	www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Sources of the aws_auth module for the NGINX ports
WWW=		https://github.com/anomalizer/ngx_aws_auth

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	anomalizer
GH_PROJECT=	ngx_aws_auth
GH_TAGNAME=	3c129c2

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

_MODDIR=	share/nginx/modules/${PORTNAME}
MODULESDIR=	${PREFIX}/${_MODDIR}

PLIST_FILES=	${_MODDIR}/config \
		${_MODDIR}/aws_functions.h \
		${_MODDIR}/crypto_helper.h \
		${_MODDIR}/crypto_helper_openssl.c \
		${_MODDIR}/ngx_http_aws_auth.c

do-install:
	@${MKDIR} ${STAGEDIR}${MODULESDIR}
	${INSTALL_DATA} ${WRKSRC}/config ${STAGEDIR}${MODULESDIR}
	${INSTALL_DATA} ${WRKSRC}/aws_functions.h \
		${WRKSRC}/crypto_helper.h \
		${WRKSRC}/crypto_helper_openssl.c \
		${WRKSRC}/ngx_http_aws_auth.c \
		${STAGEDIR}${MODULESDIR}

.include <bsd.port.mk>
