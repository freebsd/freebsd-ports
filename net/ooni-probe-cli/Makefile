PORTNAME=		ooni-probe-cli
DISTVERSIONPREFIX=	v
DISTVERSION=		3.27.0
CATEGORIES=		net www benchmarks

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Next generation OONI Probe CLI
WWW=		https://ooni.org/about/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss

USES=		go:1.24,modules

GO_BUILDFLAGS=	-ldflags '-s -w -extldflags "-static"'
GO_MODULE=	github.com/ooni/probe-cli/v3
GO_TARGET=	./cmd/ooniprobe

PLIST_FILES=	bin/ooniprobe

.include <bsd.port.mk>
