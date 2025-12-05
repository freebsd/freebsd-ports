PORTNAME=	yggdrasil
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.12
PORTREVISION=	3
CATEGORIES=	net

MAINTAINER=	freebsd@neilalexander.dev
COMMENT=	Experimental end-to-end encrypted self-arranging IPv6 network
WWW=		https://yggdrasil-network.github.io/ \
		https://github.com/yggdrasil-network/yggdrasil-go/

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.22,modules
USE_RC_SUBR=	yggdrasil

DEPRECATED=	Uses old go, but try building without USES=go:someversion
EXPIRATION_DATE=2026-01-01

GO_MODULE=	github.com/yggdrasil-network/yggdrasil-go
GO_TARGET=	./cmd/yggdrasil \
		./cmd/yggdrasilctl

GO_BUILDFLAGS=	-ldflags="-s -w \
		-X github.com/yggdrasil-network/yggdrasil-go/src/version.buildName=${PORTNAME} \
		-X github.com/yggdrasil-network/yggdrasil-go/src/version.buildVersion=${DISTVERSION} \
		"

PLIST_FILES=	bin/yggdrasil \
		bin/yggdrasilctl

.include <bsd.port.mk>
