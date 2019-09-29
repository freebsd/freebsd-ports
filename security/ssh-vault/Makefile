# $FreeBSD$

PORTNAME=	ssh-vault
PORTVERSION=	0.12.4
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	nbari@tequila.io
COMMENT=	Encrypt/decrypt using ssh keys

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go

USE_GITHUB=	yes
GH_TUPLE=	golang:crypto:c126467:gocrypto/vendor/golang.org/x/crypto \
		golang:sys:bd9dbc1:gosys/vendor/golang.org/x/sys \
		ssh-vault:crypto:ae180e0:crypto/vendor/github.com/ssh-vault/crypto \
		ssh-vault:ssh2pem:c1edc64:ssh2pem/vendor/github.com/ssh-vault/ssh2pem

GH_SUBDIR=	src/github.com/${PORTNAME}/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "-s -w -X main.version=${PORTVERSION}"
GO_TARGET=	./cmd/ssh-vault

PLIST_FILES=	bin/ssh-vault

.include <bsd.port.mk>
