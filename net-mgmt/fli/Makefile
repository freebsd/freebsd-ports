PORTNAME=	fli
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0
PORTREVISION=	2
CATEGORIES=	net-mgmt

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Analyze AWS VPC Flow Logs with ease
WWW=		https://github.com/fractalops/fli

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	fractalops

GO_MODULE=	github.com/fractalops/fli
GO_TARGET=	./cmd/fli

PLIST_FILES=	bin/fli

.include <bsd.port.mk>
