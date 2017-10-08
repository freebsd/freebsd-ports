# $FreeBSD$

PORTNAME=	ssh-vault
PORTVERSION=	0.12.3
CATEGORIES=	security

MAINTAINER=	nbari@tequila.io
COMMENT=	Encrypt/decrypt using ssh keys

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	go>=1.7:lang/go \
		go.crypto>=20160709:security/go.crypto

USES=		go

USE_GITHUB=	yes
GH_TUPLE=	ssh-vault:crypto:ae180e0:crypto/src/github.com/ssh-vault/crypto \
		ssh-vault:ssh2pem:c1edc64:ssh2pem/src/github.com/ssh-vault/ssh2pem
GH_SUBDIR=	src/github.com/${PORTNAME}/${PORTNAME}

STRIP=		# stripping can break go binaries

PLIST_FILES=	bin/ssh-vault

post-patch:
	@${MKDIR} ${WRKSRC}/src/golang.org
	@${LN} -sf ${LOCALBASE}/share/go/src/golang.org/x ${WRKSRC}/src/golang.org/x

do-build:
	@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}; \
	${SETENV} ${BUILD_ENV} GOPATH=${WRKSRC} go build -ldflags \
	"-s -w -X main.version=${PORTVERSION}" -o ssh-vault cmd/ssh-vault/main.go;

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/ssh-vault/ssh-vault/ssh-vault ${STAGEDIR}${PREFIX}/bin/ssh-vault

.include <bsd.port.mk>
