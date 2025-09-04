PORTNAME=	yubikey-agent
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.6
PORTREVISION=	22
CATEGORIES=	security sysutils

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Seamless ssh-agent for YubiKeys
WWW=		https://filippo.io/yubikey-agent

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpcsclite.so:devel/pcsc-lite
RUN_DEPENDS=	RSA_SecurID_getpasswd:devel/libccid

USES=		go:modules
USE_GITHUB=	yes

GH_ACCOUNT=	FiloSottile
GH_TUPLE=	go-piv:piv-go:v1.10.0:go_piv_piv_go/vendor/github.com/go-piv/piv-go \
		golang:crypto:v0.4.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:sys:v0.3.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.3.0:golang_term/vendor/golang.org/x/term \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		twpayne:go-pinentry-minimal:2a5dc4396c2a:twpayne_go_pinentry_minimal/vendor/github.com/twpayne/go-pinentry-minimal

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
