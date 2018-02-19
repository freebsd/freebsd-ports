# $FreeBSD$

PORTNAME=	cryptoballot
DISTVERSION=	g20170928
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cryptographically secure online voting

LICENSE=	AGPLv3

BUILD_DEPENDS=	go:lang/go

USE_GITHUB=	yes
GH_TAGNAME=	ec9df0a
GH_TUPLE=	${PORTNAME}:entropychecker:188ae6c:entropychecker/src/github.com/${PORTNAME}/entropychecker \
		${PORTNAME}:fdh:5eb31ce:fdh/src/github.com/${PORTNAME}/fdh \
		${PORTNAME}:rsablind:14f9913:rsablind/src/github.com/${PORTNAME}/rsablind \
		urfave:cli:v1.20.0:cli/src/github.com/urfave/cli \
		phayes:decryptpem:7e4f5bc:decryptpem/src/github.com/phayes/decryptpem \
		phayes:errors:ad407e6:errors/src/github.com/phayes/errors \
		dlintw:goconf:dcc0709:goconf/src/github.com/dlintw/goconf \
		Sam-Izdat:govote:7d55c89:govote/src/github.com/Sam-Izdat/govote \
		lib:pq:88edab0:pq/src/github.com/lib/pq \
		golang:crypto:650f4a3:crypto/src/golang.org/x/crypto \
		golang:sys:37707fd:sys/src/golang.org/x/sys
GH_SUBDIR=	src/github.com/${PORTNAME}/${PORTNAME}

PROGS=		servers/ballotbox servers/electionclerk \
		utils/cryptoballot \
		utils/cryptoballot-getid utils/cryptoballot-public-key \
		utils/cryptoballot-sign utils/cryptoballot-signature-request

PLIST_FILES=	${PROGS:C/.*\//bin\//}

do-build:
.for p in ${PROGS}
	@cd ${WRKSRC}/${GH_SUBDIR}/${p}/ && \
		${SETENV} GOPATH=${WRKSRC} go build -o ${p:C/.*\///}
.endfor

do-install:
.for p in ${PROGS}
	${INSTALL_PROGRAM} ${WRKSRC}/${GH_SUBDIR}/${p}/${p:C/.*\///} ${STAGEDIR}${PREFIX}/bin/${p:C/.*\///}
.endfor

.include <bsd.port.mk>
