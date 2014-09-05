# $FreeBSD$

PORTNAME=	go.crypto
PORTVERSION=	20140828
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
		${GO_PKGNAME}/twofish		\
		${GO_PKGNAME}/xtea		\
		${GO_PKGNAME}/xts

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/lang/go/files/bsd.go.mk"
.include <bsd.port.post.mk>
