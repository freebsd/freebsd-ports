PORTNAME=	go-tuf
DISTVERSIONPREFIX=	v
DISTVERSION=	2.6.0
CATEGORIES=	security

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Framework for Securing Software
WWW=		https://theupdateframework.io

LICENSE=	Apache-2.0
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe go:1.27+,modules
CPE_VENDOR=	theupdateframework

GO_TARGET=	./examples/cli/tuf-client
GO_MODULE=	github.com/theupdateframework/go-tuf/v2

PLIST_FILES=	bin/tuf-client

.include <bsd.port.mk>
