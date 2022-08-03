PORTNAME=	obfs4proxy
DISTVERSION=	0.0.13
PORTREVISION=	4
CATEGORIES=	security net
PKGNAMESUFFIX=	-tor
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Pluggable transport proxy for Tor (obfs4, The Obfuscator)

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe go:modules tar:xz

CPE_VENDOR=	torproject

USE_GITHUB=	nodefault
GH_TUPLE=	FiloSottile:edwards25519:390f27c3be20:filosottile_edwards25519/vendor/filippo.io/edwards25519 \
		dchest:siphash:v1.2.2:siphash/vendor/github.com/dchest/siphash \
		dsnet:compress:f669936:dsnet_compress/vendor/github.com/dsnet/compress \
		golang:crypto:a769d52b0f97:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:e18ecbb05110:golang_net/vendor/golang.org/x/net \
		golang:sys:665e8c7367d1:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.3:golang_text/vendor/golang.org/x/text \
		torbsd:goptlib:v1.2.0:goptlib/vendor/git.torproject.org/pluggable-transports/goptlib.git

USE_GITLAB=	yes
GL_ACCOUNT=	yawning
GL_PROJECT=	obfs4
GL_COMMIT=	77af0cba934d73c4baeb709560bcfc9a9fbc661c
GL_TUPLE=	yawning:bsaes:0a714cd429ec754482b4001e918db30cd2094405:yawning_bsaes/vendor/gitlab.com/yawning/bsaes.git \
		yawning:edwards25519-extra:2f91fcc9fbdb888f3c795849b6777940135559b7:yawning_edwards25519extra/vendor/gitlab.com/yawning/edwards25519-extra.git \
		yawning:utls:f1bcf4b40e4596d0ccd1dbf8f3a9f4922f9759ca:yawning_utls/vendor/gitlab.com/yawning/utls.git

GO_PKGNAME=	gitlab.com/yawning/obfs4
GO_TARGET=	./obfs4proxy

SUB_FILES=	pkg-message

PLIST_FILES=	bin/obfs4proxy \
		man/man1/obfs4proxy.1.gz

post-patch:
	${LN} -s ${WRKSRC} ${WRKSRC}/vendor/${GO_PKGNAME}

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/obfs4proxy.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
