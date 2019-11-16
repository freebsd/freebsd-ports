# $FreeBSD$

PORTNAME=	cryptoballot
DISTVERSION=	g20181015
PORTREVISION=	1
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cryptographically secure online voting

LICENSE=	AGPLv3

USES=		go

USE_GITHUB=	yes
GH_TAGNAME=	3753e1b
GH_TUPLE=	${PORTNAME}:entropychecker:188ae6c:entropychecker/vendor/github.com/${PORTNAME}/entropychecker \
		${PORTNAME}:fdh:5eb31ce:fdh/vendor/github.com/${PORTNAME}/fdh \
		${PORTNAME}:rsablind:14f9913:rsablind/vendor/github.com/${PORTNAME}/rsablind \
		urfave:cli:v1.20.0:cli/vendor/github.com/urfave/cli \
		phayes:decryptpem:7e4f5bc:decryptpem/vendor/github.com/phayes/decryptpem \
		phayes:errors:ad407e6:errors/vendor/github.com/phayes/errors \
		dlintw:goconf:dcc0709:goconf/vendor/github.com/dlintw/goconf \
		Sam-Izdat:govote:7d55c89:govote/vendor/github.com/Sam-Izdat/govote \
		lib:pq:88edab0:pq/vendor/github.com/lib/pq \
		golang:crypto:650f4a3:crypto/vendor/golang.org/x/crypto \
		golang:sys:37707fd:sys/vendor/golang.org/x/sys
GH_SUBDIR=	src/github.com/${PORTNAME}/${PORTNAME}

GO_TARGET=	./servers/ballotbox ./servers/electionclerk \
		./utils/cryptoballot \
		./utils/cryptoballot-getid ./utils/cryptoballot-public-key \
		./utils/cryptoballot-sign ./utils/cryptoballot-signature-request

PLIST_FILES=	${GO_TARGET:C/.*\//bin\//}

.include <bsd.port.mk>
