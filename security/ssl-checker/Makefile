PORTNAME=	ssl-checker
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.7
CATEGORIES=	security

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Fast and beautiful program to check all your https endpoints
WWW=		https://github.com/fabio42/ssl-checker

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	fabio42

GO_MODULE=	github.com/fabio42/ssl-checker

PLIST_FILES=	bin/ssl-checker

.include <bsd.port.mk>
