PORTNAME=	pipeform
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	TUI for Terraform runtime progress
WWW=		https://github.com/magodo/pipeform

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/magodo/pipeform

CGO_ENABLED=	0

PLIST_FILES=	bin/pipeform

.include <bsd.port.mk>
