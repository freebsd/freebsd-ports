# $FreeBSD$

PORTNAME=	age
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
DISTVERSIONSUFFIX=	-beta2
CATEGORIES=	security

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Simple, modern and secure file encryption tool

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	FiloSottile
GH_TUPLE=	\
		Filosottile:go:9090b284250b:filosottile_go/vendor/golang.org/x/crypto \
		golang:sys:97732733099d:golang_sys/vendor/golang.org/x/sys

GO_TARGET=	./cmd/age \
		./cmd/age-keygen

PLIST_FILES=	${GO_TARGET:C/.\/cmd/bin/}

.include <bsd.port.mk>
