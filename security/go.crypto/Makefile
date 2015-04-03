# $FreeBSD$

PORTNAME=	go.crypto
PORTVERSION=	20141121
CATEGORIES=	security devel
MASTER_SITES=	http://www.c-s.li/ports/

MAINTAINER=	jlaffaye@FreeBSD.org
COMMENT=	Additional cryptography packages for Go

GO_PKGNAME=	code.google.com/p/go.crypto
GO_TARGET=	${GO_PKGNAME}/bcrypt		\
		${GO_PKGNAME}/blowfish		\
		${GO_PKGNAME}/bn256		\
		${GO_PKGNAME}/cast5		\
		${GO_PKGNAME}/curve25519	\
		${GO_PKGNAME}/hkdf		\
		${GO_PKGNAME}/md4		\
		${GO_PKGNAME}/nacl/box		\
		${GO_PKGNAME}/nacl/secretbox	\
		${GO_PKGNAME}/ocsp		\
		${GO_PKGNAME}/openpgp		\
		${GO_PKGNAME}/openpgp/armor	\
		${GO_PKGNAME}/openpgp/clearsign	\
		${GO_PKGNAME}/openpgp/elgamal	\
		${GO_PKGNAME}/openpgp/errors	\
		${GO_PKGNAME}/openpgp/packet	\
		${GO_PKGNAME}/openpgp/s2k	\
		${GO_PKGNAME}/otr		\
		${GO_PKGNAME}/pbkdf2		\
		${GO_PKGNAME}/poly1305		\
		${GO_PKGNAME}/ripemd160		\
		${GO_PKGNAME}/salsa20		\
		${GO_PKGNAME}/salsa20/salsa	\
		${GO_PKGNAME}/scrypt		\
		${GO_PKGNAME}/sha3		\
		${GO_PKGNAME}/ssh		\
		${GO_PKGNAME}/ssh/agent		\
		${GO_PKGNAME}/ssh/terminal	\
		${GO_PKGNAME}/ssh/test		\
		${GO_PKGNAME}/ssh/testdata	\
		${GO_PKGNAME}/twofish		\
		${GO_PKGNAME}/xtea		\
		${GO_PKGNAME}/xts

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/lang/go/files/bsd.go.mk"

post-patch:
	@${REINPLACE_CMD} -e 's|golang\.org\/x\/crypto|code\.google\.com\/p\/go\.crypto|g' \
		${WRKSRC}/bcrypt/bcrypt.go \
		${WRKSRC}/nacl/box/box.go \
		${WRKSRC}/nacl/secretbox/secretbox.go \
		${WRKSRC}/openpgp/armor/armor.go \
		${WRKSRC}/openpgp/clearsign/clearsign.go \
		${WRKSRC}/openpgp/keys.go \
		${WRKSRC}/openpgp/packet/compressed.go \
		${WRKSRC}/openpgp/packet/encrypted_key.go \
		${WRKSRC}/openpgp/packet/one_pass_signature.go \
		${WRKSRC}/openpgp/packet/opaque.go \
		${WRKSRC}/openpgp/packet/packet.go \
		${WRKSRC}/openpgp/packet/private_key.go \
		${WRKSRC}/openpgp/packet/public_key.go \
		${WRKSRC}/openpgp/packet/public_key_v3.go \
		${WRKSRC}/openpgp/packet/reader.go \
		${WRKSRC}/openpgp/packet/signature.go \
		${WRKSRC}/openpgp/packet/signature_v3.go \
		${WRKSRC}/openpgp/packet/symmetric_key_encrypted.go \
		${WRKSRC}/openpgp/packet/symmetrically_encrypted.go \
		${WRKSRC}/openpgp/read.go \
		${WRKSRC}/openpgp/s2k/s2k.go \
		${WRKSRC}/openpgp/write.go \
		${WRKSRC}/salsa20/salsa20.go \
		${WRKSRC}/scrypt/scrypt.go \
		${WRKSRC}/ssh/agent/client.go \
		${WRKSRC}/ssh/agent/forward.go \
		${WRKSRC}/ssh/agent/keyring.go \
		${WRKSRC}/ssh/agent/server.go

.include <bsd.port.post.mk>
