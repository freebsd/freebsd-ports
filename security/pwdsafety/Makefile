PORTNAME=	pwdsafety
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.1
CATEGORIES=	security

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Command line tool that checks how much a password is safe
WWW=		https://github.com/edoardottt/pwdsafety

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/edoardottt/pwdsafety
GO_TARGET=	./cmd/pwdsafety

PLIST_FILES=	bin/pwdsafety

.include <bsd.port.mk>
