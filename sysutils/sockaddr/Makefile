PORTNAME=	sockaddr
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.5
CATEGORIES=	sysutils

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Command line utility for querying IP information
WWW=		https://github.com/hashicorp/go-sockaddr/tree/master/cmd/sockaddr

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_MODULE=	github.com/hashicorp/go-sockaddr
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/sockaddr

.include <bsd.port.mk>
