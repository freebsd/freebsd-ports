PORTNAME=	totp-cli
PORTVERSION=	1.3.3
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Authy/Google Authenticator like TOTP CLI tool
WWW=		https://github.com/yitsushi/totp-cli

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	nodefault
GH_TUPLE=	golang:sys:v0.6.0:sys

GO_MODULE=	github.com/yitsushi/totp-cli

PLIST_FILES=	bin/totp-cli

pre-patch:
	${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
	${LN} -s ${WRKDIR}/sys-* ${WRKSRC}/vendor/golang.org/x/sys

.include <bsd.port.mk>
