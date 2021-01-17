# $FreeBSD$

PORTNAME=	age
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
DISTVERSIONSUFFIX=	-beta6
CATEGORIES=	security

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Simple, modern and secure file encryption tool

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	FiloSottile
GH_TUPLE=	FiloSottile:edwards25519:v1.0.0-alpha.2:filosottile_edwards25519/vendor/filippo.io/edwards25519 \
		golang:crypto:0ec3e9974c59:golang_crypto/vendor/golang.org/x/crypto \
		golang:sys:97732733099d:golang_sys/vendor/golang.org/x/sys \
		sergi:go-diff:v1.1.0:sergi_go_diff/vendor/github.com/sergi/go-diff

GO_TARGET=	./cmd/age \
		./cmd/age-keygen

PLIST_FILES=	${GO_TARGET:C/.\/cmd/bin/}

.include <bsd.port.mk>
