PORTNAME=	hcloud
DISTVERSIONPREFIX=	v
DISTVERSION=	1.46.0
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Official Hetzner Cloud command-line interface
WWW=		https://github.com/hetznercloud/cli

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules,1.21

GO_MODULE=	github.com/hetznercloud/cli
GO_TARGET=	./cmd/hcloud

PLIST_FILES=	bin/hcloud

.include <bsd.port.mk>
