PORTNAME=	wireproxy
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.0-20220329034706
DISTVERSIONSUFFIX=	-4a4e7a79ab7f
CATEGORIES=	net

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Wireguard client that exposes itself as a socks5 proxy

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/octeep/wireproxy
GO_TARGET=	./cmd/wireproxy

PLIST_FILES=	bin/wireproxy

.include <bsd.port.mk>
