PORTNAME=	nats-surveyor
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.3
CATEGORIES=	net

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	NATS Monitoring, Simplified
WWW=		https://github.com/nats-io/nats-surveyor

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	nats-io

GO_MODULE=	github.com/nats-io/nats-surveyor

PLIST_FILES=	bin/nats-surveyor

.include <bsd.port.mk>
