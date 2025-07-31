PORTNAME=	tscli
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.15
CATEGORIES=	security

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	CLI tool to interact with the Tailscale API
WWW=		https://github.com/jaxxstorm/tscli

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_MODULE=	github.com/jaxxstorm/tscli
GO_TARGET=	./cmd/tscli:tscli
GO_BUILDFLAGS=	-ldflags "\
			-X 'github.com/jaxxstorm/tscli/pkg/version.Version=${DISTVERSIONPREFIX}${DISTVERSION}'"

PLIST_FILES=	bin/tscli

.include <bsd.port.mk>
