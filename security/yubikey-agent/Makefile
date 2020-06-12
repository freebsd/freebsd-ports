# $FreeBSD$

PORTNAME=	yubikey-agent
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.1
CATEGORIES=	security sysutils

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Seamless ssh-agent for YubiKeys

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpcsclite.so:devel/pcsc-lite
RUN_DEPENDS=	RSA_SecurID_getpasswd:devel/libccid

USES=		go:modules
USE_GITHUB=	yes

GH_ACCOUNT=	FiloSottile
		# github.com/go-piv/piv-go/commit/a3e5767 (Add FreeBSD Support)
GH_TUPLE=	go-piv:piv-go:a3e5767:go_piv_piv_go/vendor/github.com/go-piv/piv-go \
	golang:crypto:4b2356b1ed79:golang_crypto/vendor/golang.org/x/crypto \
	golang:sys:1957bb5e6d1f:golang_sys/vendor/golang.org/x/sys \
	gopasspw:gopass:v1.9.1:gopasspw_gopass/vendor/github.com/gopasspw/gopass \
	pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
