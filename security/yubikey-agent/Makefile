PORTNAME=	yubikey-agent
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.5
PORTREVISION=	3
CATEGORIES=	security sysutils

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Seamless ssh-agent for YubiKeys

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	constant 2148532270 overflows _Ctype_long

LIB_DEPENDS=	libpcsclite.so:devel/pcsc-lite
RUN_DEPENDS=	RSA_SecurID_getpasswd:devel/libccid

USES=		go:modules
USE_GITHUB=	yes

GH_ACCOUNT=	FiloSottile
GH_TUPLE=	go-piv:piv-go:v1.7.0:go_piv_piv_go/vendor/github.com/go-piv/piv-go \
	golang:crypto:83a5a9bb288b:golang_crypto/vendor/golang.org/x/crypto \
	golang:sys:9a76102bfb43:golang_sys/vendor/golang.org/x/sys \
	golang:term:2321bbc49cbf:golang_term/vendor/golang.org/x/term \
	gopasspw:pinentry:v0.0.2:gopasspw_pinentry/vendor/github.com/gopasspw/pinentry \
	pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
