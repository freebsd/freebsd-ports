# $FreeBSD$

PORTNAME=	xmpp-client
PORTVERSION=	20170324
PORTREVISION=	1
CATEGORIES=	net-im

MAINTAINER=	cs@FreeBSD.org
COMMENT=	XMPP client with OTR support

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	go:lang/go

USE_GITHUB=	yes
GH_TUPLE=	agl:xmpp-client:3030ad4:DEFAULT/src/github.com/agl/xmpp-client \
		golang:crypto:c126467:crypto/src/golang.org/x/crypto \
		golang:net:a680a1e:net/src/golang.org/x/net \
		golang:sys:ac767d6:sys/src/golang.org/x/sys

PLIST_FILES=	bin/xmpp-client

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} go build  -o ${PORTNAME}

do-test:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} go test . ./xmpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
