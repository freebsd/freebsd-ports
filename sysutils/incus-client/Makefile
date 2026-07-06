PORTNAME=	incus-client
PORTVERSION=	7.0.0
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Incus command-line client
WWW=		https://github.com/lxc/incus

LICENSE=	APACHE20

USES=		cpe go:1.25+,modules
CPE_PRODUCT=	incus

GO_MODULE=	github.com/lxc/incus/v7
GO_TARGET=	./cmd/incus

PLIST_FILES=	bin/incus

.include <bsd.port.mk>
