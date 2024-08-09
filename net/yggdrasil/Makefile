PORTNAME=	yggdrasil
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.7
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	freebsd@neilalexander.dev
COMMENT=	Experimental end-to-end encrypted self-arranging IPv6 network
WWW=		https://yggdrasil-network.github.io/

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules go:1.21
GO_MODULE=	github.com/yggdrasil-network/yggdrasil-go
GO_TARGET=	./cmd/yggdrasil \
		./cmd/yggdrasilctl

GO_BUILDFLAGS=	-ldflags="-s -w \
		-X github.com/yggdrasil-network/yggdrasil-go/src/version.buildName=${PORTNAME} \
		-X github.com/yggdrasil-network/yggdrasil-go/src/version.buildVersion=${PORTVERSION} \
		"

PLIST_FILES=	bin/yggdrasil \
		bin/yggdrasilctl

USE_RC_SUBR=	yggdrasil

.include <bsd.port.mk>
