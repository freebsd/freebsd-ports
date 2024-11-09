PORTNAME=	yggdrasil
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.9
CATEGORIES=	net

MAINTAINER=	freebsd@neilalexander.dev
COMMENT=	Experimental end-to-end encrypted self-arranging IPv6 network
WWW=		https://yggdrasil-network.github.io/

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules go:1.21
USE_RC_SUBR=	yggdrasil

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
