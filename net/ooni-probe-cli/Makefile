PORTNAME=	ooni-probe-cli
DISTVERSIONPREFIX=	v
DISTVERSION=	3.31.1
PORTREVISION=	1
CATEGORIES=	net www benchmarks

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Next generation OONI Probe CLI
WWW=		https://ooni.org/about/

LICENSE=	GPL-3.0-only # top-level license
LICENSE+=	Apache-2.0 BSD-3-Clause MIT # additional licenses
LICENSE_COMB=	multi
LICENSE_FILE_GPL-3.0-only=	${WRKSRC}/LICENSE

RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss

USES=		go:modules

GO_MODULE=	github.com/ooni/probe-cli/v3
GO_TARGET=	./cmd/ooniprobe
GO_BUILDFLAGS=	-ldflags '-s -w -extldflags "-static"'

PIE_UNSAFE=	yes

PLIST_FILES=	bin/ooniprobe

.include <bsd.port.mk>
