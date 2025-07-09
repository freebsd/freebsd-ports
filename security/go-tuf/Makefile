PORTNAME=	go-tuf
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.1
PORTREVISION=	3
CATEGORIES=	security

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Framework for Securing Software
WWW=		https://theupdateframework.io

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe go:1.24,modules
CPE_VENDOR=	theupdateframework

GO_TARGET=	./examples/cli/tuf-client
GO_MODULE=	github.com/theupdateframework/go-tuf/v2

PLIST_FILES=	bin/tuf-client

.include <bsd.port.mk>
