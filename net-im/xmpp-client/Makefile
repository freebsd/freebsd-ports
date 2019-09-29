# $FreeBSD$

PORTNAME=	xmpp-client
PORTVERSION=	20170324
PORTREVISION=	1
CATEGORIES=	net-im

MAINTAINER=	cs@FreeBSD.org
COMMENT=	XMPP client with OTR support

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go

USE_GITHUB=	yes
GH_TUPLE=	agl:xmpp-client:3030ad4:DEFAULT/vendor/github.com/agl/xmpp-client \
		golang:crypto:c126467:crypto/vendor/golang.org/x/crypto \
		golang:net:a680a1e:net/vendor/golang.org/x/net \
		golang:sys:ac767d6:sys/vendor/golang.org/x/sys

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}

PLIST_FILES=	bin/xmpp-client

do-test:
	cd ${WRKSRC}; \
		${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} test ${GO_BUILDFLAGS} . ./xmpp

.include <bsd.port.mk>
