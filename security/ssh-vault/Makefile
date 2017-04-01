# $FreeBSD$

PORTNAME=       ssh-vault
PORTVERSION=    0.10.0
CATEGORIES=     security

MAINTAINER=     nbari@tequila.io
COMMENT=        Encrypt/decrypt using ssh keys

LICENSE=        BSD3CLAUSE
LICENSE_FILE=   ${WRKSRC}/LICENSE

BUILD_DEPENDS=  go>=1.7:lang/go \
		go.crypto>=20160709:security/go.crypto

USES=           go

USE_GITHUB=     yes
GH_TUPLE=	ssh-vault:crypto:ae180e0:crypto \
		ssh-vault:ssh2pem:228a306:ssh2pem \
		kr:pty:ce7fa45:pty \
		keybase:go-keychain:fc62173:keychain

STRIP=		# stripping can break go binaries

PLIST_FILES=	bin/ssh-vault

post-patch:
	@${MKDIR} ${WRKSRC}/src/golang.org \
	${WRKSRC}/src/github.com/ssh-vault/ssh-vault
.for src in cmd a_test.go cache.go cache_test.go close.go create.go \
	create_test.go edit.go encode.go getkey.go getkey_test.go shred.go \
	shred_test.go vault.go vault_test.go view.go get_password.go \
	get_password_prompt.go
	@${MV} ${WRKSRC}/${src} \
	${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}
.endfor
	@${MV} ${WRKSRC_crypto}/${src} \
		${WRKSRC}/src/github.com/${GH_ACCOUNT}/crypto
	@${MV} ${WRKSRC_ssh2pem}/${src} \
		${WRKSRC}/src/github.com/${GH_ACCOUNT}/ssh2pem
	@${MKDIR} ${WRKSRC}/src/github.com/keybase
	@${MV} ${WRKDIR}/go-keychain-fc62173 \
		${WRKSRC}/src/github.com/keybase/go-keychain
	@${MKDIR} ${WRKSRC}/src/github.com/kr
	@${MV} ${WRKDIR}/pty-ce7fa45 \
		${WRKSRC}/src/github.com/kr/pty
	@${LN} -sf ${LOCALBASE}/share/go/src/golang.org/x ${WRKSRC}/src/golang.org/x

do-build:
	@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}; \
	${SETENV} ${BUILD_ENV} GOPATH=${WRKSRC} go build -ldflags \
	"-X main.version=${PORTVERSION}" -o ssh-vault cmd/ssh-vault/main.go;

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/ssh-vault/ssh-vault/ssh-vault ${STAGEDIR}${PREFIX}/bin/ssh-vault

.include <bsd.port.mk>
