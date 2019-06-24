# $FreeBSD$

PORTNAME=	obfs4proxy
DISTVERSION=	0.0.11
CATEGORIES=	security net ipv6
MASTER_SITES=	https://people.torproject.org/~yawning/releases/${PORTNAME}/
PKGNAMESUFFIX=	-tor
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Pluggable transport proxy for Tor (obfs4, The Obfuscator)

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKDIR}/LICENSE

USES=		cpe go tar:xz

CPE_VENDOR=	torproject

GO_TARGET=	gitlab.com/yawning/obfs4.git

USE_GITHUB=	nodefault
GH_TUPLE=	ahf:goptlib:7d56ec4:goptlib/src/git.torproject.org/pluggable-transports/goptlib.git \
		agl:ed25519:5312a61:ed25519/src/github.com/agl/ed25519 \
		dchest:siphash:v1.2.1:siphash/src/github.com/dchest/siphash \
		dsnet:compress:v0.0.1:dsnet_compress/src/github.com/dsnet/compress \
		golang:crypto:cc06ce4:golang_crypto/src/golang.org/x/crypto \
		golang:net:3b0461e:golang_net/src/golang.org/x/net \
		golang:text:v0.3.0:golang_text/src/golang.org/x/text \
		golang:sys:d432491:golang_sys/src/golang.org/x/sys \
		Yawning:bsaes:26d1add:Yawning_bsaes/src/git.schwanenlied.me/yawning/bsaes.git

USE_GITLAB=	nodefault
GL_TUPLE=	yawning:utls:dd99191913e03b2cd62655cd260d79187fbf8a9f:yawning_utls/src/gitlab.com/yawning/utls.git

SUB_FILES=	pkg-message

PLIST_FILES=	bin/obfs4proxy \
		man/man1/obfs4proxy.1.gz

do-build:
	@${RM} ${WRKDIR}/go.mod
	@${MKDIR} ${GO_WRKSRC}/src/${GO_TARGET:H}
	@${RLN} ${WRKDIR} ${GO_WRKSRC}/src/${GO_TARGET}
	@${RLN} ${WRKDIR}/src ${GO_WRKSRC}/src/${GO_TARGET}/src
	@(cd ${WRKDIR}/${PORTNAME} && \
	  ${SETENV} ${MAKE_ENV} ${GO_ENV} GOPATH=${WRKDIR}/src/${PORTNAME} ${GO_CMD} \
	  build ${GO_BUILDFLAGS} -o ${WRKDIR}/bin/${PORTNAME})

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/doc/obfs4proxy.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
