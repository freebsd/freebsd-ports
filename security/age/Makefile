# $FreeBSD$

PORTNAME=	age
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
DISTVERSIONSUFFIX=	-beta6
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Simple, modern and secure file encryption tool

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	filippo.io/age
GO_TARGET=	./cmd/age \
		./cmd/age-keygen

PLIST_FILES=	${GO_TARGET:C/.\/cmd/bin/}

.include <bsd.port.mk>
