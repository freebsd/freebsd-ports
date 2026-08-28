PORTNAME=	nats-surveyor
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.11
PORTREVISION=	3
CATEGORIES=	net

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	NATS Monitoring, Simplified
WWW=		https://github.com/nats-io/nats-surveyor

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/nats-io/nats-surveyor
GO_LDFLAGS=	-X ${GO_MODULE}/cmd.Version=${DISTVERSIONFULL}

PLIST_FILES=	bin/nats-surveyor

.include <bsd.port.mk>
