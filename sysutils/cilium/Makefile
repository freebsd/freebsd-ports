PORTNAME=	cilium
DISTVERSIONPREFIX=	v
DISTVERSION=	0.16.24
PORTREVISION=	4
CATEGORIES=	sysutils

MAINTAINER=	dutra@FreeBSD.org
COMMENT=	Manage Kubernetes clusters running Cilium
WWW=		https://github.com/cilium/cilium-cli

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.23,modules

GO_MODULE=	github.com/cilium/cilium-cli
GO_BUILDFLAGS=	-ldflags="\
		-X github.com/cilium/cilium/cilium-cli/defaults.CLIVersion=${DISTVERSION}"

GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
