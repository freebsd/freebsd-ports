PORTNAME=	runj
DISTVERSION=	g20230316
PORTREVISION?=	3
CATEGORIES=	sysutils

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Experimental, proof-of-concept OCI-compatible runtime for jails
WWW=		https://github.com/samuelkarp/runj

LICENSE=	APACHE20 BSD2CLAUSE BSD3CLAUSE MIT
LICENSE_COMB=	multi

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	samuelkarp
GH_TAGNAME=	8158e558a

.include "Makefile.deps"

GO_TARGET=	./cmd/runj \
		./cmd/runj-entrypoint \
		./cmd/containerd-shim-runj-v1

PLIST_FILES=	bin/runj \
		bin/runj-entrypoint \
		bin/containerd-shim-runj-v1

.include <bsd.port.mk>
