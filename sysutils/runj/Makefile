PORTNAME=	runj
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0
PORTREVISION=	12
CATEGORIES=	sysutils

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Experimental, proof-of-concept OCI-compatible runtime for jails
WWW=		https://github.com/samuelkarp/runj

LICENSE=	APACHE20 BSD2CLAUSE BSD3CLAUSE MIT
LICENSE_COMB=	multi

USES=		go:modules

GO_MODULE=	github.com/samuelkarp/runj

GO_TARGET=	./cmd/runj \
		./cmd/runj-entrypoint \
		./cmd/containerd-shim-runj-v1

PLIST_FILES=	bin/runj \
		bin/runj-entrypoint \
		bin/containerd-shim-runj-v1

.include <bsd.port.mk>
