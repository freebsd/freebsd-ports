PORTNAME=	equinix-metal-cli
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.4
PORTREVISION=	3
CATEGORIES=	sysutils

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Command line tool for Equinix Metal services

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	equinix
GH_PROJECT=	metal-cli

.include "${.CURDIR}/Makefile.deps"

GO_BUILDFLAGS=	-ldflags "-X github.com/equinix/metal-cli/cmd.Version=v$(DISTVERSION)"
GO_TARGET=	./cmd/metal

PLIST_FILES=	bin/metal

.include <bsd.port.mk>
