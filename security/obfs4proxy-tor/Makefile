PORTNAME=	obfs4proxy
DISTVERSION=	0.0.14
PORTREVISION=	32
CATEGORIES=	security net
PKGNAMESUFFIX=	-tor
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Pluggable transport proxy for Tor (obfs4, The Obfuscator)
WWW=		https://gitlab.com/yawning/obfs4

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe go:modules tar:xz

CPE_VENDOR=	torproject

USE_GITHUB=	nodefault
GH_TUPLE=	FiloSottile:edwards25519:v1.2.0:filosottile_edwards25519/vendor/filippo.io/edwards25519 \
		dchest:siphash:v1.2.3:dchest_siphash/vendor/github.com/dchest/siphash \
		golang:crypto:v0.14.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:v0.17.0:golang_net/vendor/golang.org/x/net \
		golang:sys:v0.13.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.34.0:golang_text/vendor/golang.org/x/text \
		torbsd:goptlib:f4bb5dd5725833bd880347b8fbaf60522ed0a710:goptlib/vendor/gitlab.torproject.org/tpo/anti-censorship/pluggable-transports/goptlib

USE_GITLAB=	yes
GL_ACCOUNT=	yawning
GL_PROJECT=	obfs4
GL_TAGNAME=	c3e2d44b1033e03645cc971565175e56d86a8200
GL_TUPLE=	yawning:bsaes:0a714cd429ec754482b4001e918db30cd2094405:yawning_bsaes/vendor/gitlab.com/yawning/bsaes.git \
		yawning:edwards25519-extra:2149dcafc266f66d2487f45b156f6397f9c4760b:yawning_edwards25519extra/vendor/gitlab.com/yawning/edwards25519-extra \
		yawning:utls:f1bcf4b40e4596d0ccd1dbf8f3a9f4922f9759ca:yawning_utls/vendor/gitlab.com/yawning/utls.git

GO_PKGNAME=	gitlab.com/yawning/obfs4
GO_TARGET=	./obfs4proxy

SUB_FILES=	pkg-message

PLIST_FILES=	bin/obfs4proxy \
		share/man/man1/obfs4proxy.1.gz

post-patch:
	${LN} -s ${WRKSRC} ${WRKSRC}/vendor/${GO_PKGNAME}

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/obfs4proxy.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
