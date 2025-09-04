PORTNAME=	wireproxy
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.9
PORTREVISION=	11
CATEGORIES=	net

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Wireguard client that exposes itself as a socks5 proxy
WWW=		https://github.com/pufferffish/wireproxy

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/pufferffish/wireproxy
GO_TARGET=	./cmd/wireproxy

PLIST_FILES=	bin/wireproxy

.include <bsd.port.mk>
