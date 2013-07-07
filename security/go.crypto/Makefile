# $FreeBSD$

PORTNAME=	go.crypto
PORTVERSION=	20130706
CATEGORIES=	security devel
MASTER_SITES=	http://jlaffaye.net/ LOCAL/jlaffaye

MAINTAINER=	jlaffaye@FreeBSD.org
COMMENT=	Additional cryptography packages for Go

GO_PKGNAME=	code.google.com/p/go.crypto
GO_TARGET=	${GO_PKGNAME}/bcrypt		\
		${GO_PKGNAME}/blowfish		\
		${GO_PKGNAME}/bn256		\
		${GO_PKGNAME}/cast5		\
		${GO_PKGNAME}/curve25519	\
		${GO_PKGNAME}/md4		\
		${GO_PKGNAME}/nacl/box		\
		${GO_PKGNAME}/nacl/secretbox	\
		${GO_PKGNAME}/ocsp		\
		${GO_PKGNAME}/openpgp		\
		${GO_PKGNAME}/otr		\
		${GO_PKGNAME}/pbkdf2		\
		${GO_PKGNAME}/poly1305		\
		${GO_PKGNAME}/ripemd160		\
		${GO_PKGNAME}/salsa20		\
		${GO_PKGNAME}/scrypt		\
		${GO_PKGNAME}/sha3		\
		${GO_PKGNAME}/ssh		\
		${GO_PKGNAME}/twofish		\
		${GO_PKGNAME}/xtea		\
		${GO_PKGNAME}/xts

do-install:
	${MKDIR} ${GO_LOCAL_LIBDIR}/${GO_PKGNAME}
	(cd ${GO_WRKDIR_PKG}/ && ${COPYTREE_SHARE} \* \
		${GO_LOCAL_LIBDIR})
.for t in ${GO_TARGET}
	${MKDIR} ${GO_LOCAL_SRCDIR}/${t}
	(cd ${GO_WRKDIR_SRC}/${t}/ && ${COPYTREE_SHARE} \* \
		${GO_LOCAL_SRCDIR}/${t})
.endfor

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/lang/go/files/bsd.go.mk"
.include <bsd.port.post.mk>
