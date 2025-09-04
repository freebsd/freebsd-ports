PORTNAME=	equinix-metal-cli
DISTVERSIONPREFIX=	v
DISTVERSION=	0.25.0
PORTREVISION=	7
CATEGORIES=	sysutils

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Command line tool for Equinix Metal services
WWW=		https://github.com/equinix/metal-cli/blob/main/docs/metal.md

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_BUILDFLAGS=	-ldflags "-X github.com/equinix/metal-cli/cmd.Version=v$(DISTVERSION)"
GO_MODULE=	github.com/equinix/metal-cli
GO_TARGET=	./cmd/metal

PLIST_FILES=	bin/metal

.include <bsd.port.mk>
