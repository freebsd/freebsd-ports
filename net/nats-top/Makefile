PORTNAME=	nats-top
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.4
PORTREVISION=	7
CATEGORIES=	net

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Top like program monitor for NATS
WWW=		https://github.com/nats-io/nats-top

LICENSE=	MIT

USES=		go:modules

GO_MODULE=	github.com/nats-io/nats-top
GO_LDFLAGS=	-X main.version=${DISTVERSION}

PLIST_FILES=	bin/nats-top

.include <bsd.port.mk>
