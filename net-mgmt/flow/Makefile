PORTNAME=	flow
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.5
CATEGORIES=	net-mgmt

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Minimalist terminal dashboard for real-time network throughput
WWW=		https://github.com/programmersd21/flow

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_MODULE=	github.com/programmersd21/flow
GO_TARGET=	./cmd/flow
GO_LDFLAGS=	-X main.version=${DISTVERSION}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
