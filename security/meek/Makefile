# $FreeBSD$

PORTNAME=	meek
DISTVERSION=	0.31
CATEGORIES=	security
MASTER_SITES=	https://gitweb.torproject.org/pluggable-transports/meek.git/snapshot/ \
		https://gitweb.torproject.org/pluggable-transports/goptlib.git/snapshot/:goptlib
DISTFILES=	${PORTNAME}-${DISTVERSION}.tar.gz \
		goptlib-${GOPTLIBVERSION}.tar.gz:goptlib

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Pluggable transport proxy that relays through third-party server

LICENSE=	CC0-1.0
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	go:lang/go

USE_GITHUB=	nodefault
GH_TUPLE=	golang:crypto:c126467:crypto/src/golang.org/x/crypto \
		golang:net:a680a1e:net/src/golang.org/x/net \
		golang:text:0605a83:text/src/golang.org/x/text

GOPTLIBVERSION=	0.7

PLIST_FILES=	bin/meek-client \
		bin/meek-server \
		man/man1/meek-client.1.gz \
		man/man1/meek-server.1.gz

SUB_FILES=	pkg-message

post-extract:
	@${MKDIR} ${WRKSRC}/src/git.torproject.org/pluggable-transports
	@${LN} -s ${WRKDIR}/${PORTNAME}-${PORTVERSION} ${WRKSRC}/src/git.torproject.org/pluggable-transports/${PORTNAME}
	@${LN} -s ${WRKDIR}/goptlib-${GOPTLIBVERSION} ${WRKSRC}/src/git.torproject.org/pluggable-transports/goptlib.git

do-build:
	@cd ${WRKSRC}/meek-client && ${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} go build
	@cd ${WRKSRC}/meek-server && ${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} go build

do-test:
	@cd ${WRKSRC}/meek-client && ${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} go test
	@cd ${WRKSRC}/meek-server && ${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} go test

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/meek-client/meek-client ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/meek-server/meek-server ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/meek-server.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/meek-client.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
