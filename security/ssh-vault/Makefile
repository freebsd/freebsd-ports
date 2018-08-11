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
GH_TUPLE=	golang:crypto:c126467:gocrypto/src/golang.org/x/crypto \
		golang:sys:bd9dbc1:gosys/src/golang.org/x/sys \
		ssh-vault:crypto:ae180e0:crypto/src/github.com/ssh-vault/crypto \
		ssh-vault:ssh2pem:c1edc64:ssh2pem/src/github.com/ssh-vault/ssh2pem

GH_SUBDIR=	src/github.com/${PORTNAME}/${PORTNAME}

PLIST_FILES=	bin/ssh-vault

do-build:
	@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}; \
	${SETENV} ${MAKE_ENV} ${BUILD_ENV} GOPATH=${WRKSRC} go build -ldflags \
	"-s -w -X main.version=${PORTVERSION}" -o ssh-vault cmd/ssh-vault/main.go;

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/ssh-vault/ssh-vault/ssh-vault \
		${STAGEDIR}${PREFIX}/bin/ssh-vault

.include <bsd.port.mk>
