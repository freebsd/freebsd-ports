# $FreeBSD$

PORTNAME=	meek
DISTVERSION=	0.31
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://gitweb.torproject.org/pluggable-transports/meek.git/snapshot/ \
		https://gitweb.torproject.org/pluggable-transports/goptlib.git/snapshot/:goptlib
DISTFILES=	${PORTNAME}-${DISTVERSION}.tar.gz \
		goptlib-${GOPTLIBVERSION}.tar.gz:goptlib

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Pluggable transport proxy that relays through third-party server

LICENSE=	CC0-1.0
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		go

USE_GITHUB=	nodefault
GH_TUPLE=	golang:crypto:c126467:crypto/vendor/golang.org/x/crypto \
		golang:net:a680a1e:net/vendor/golang.org/x/net \
		golang:text:0605a83:text/vendor/golang.org/x/text

GO_TARGET=	./meek-client \
		./meek-server

GOPTLIBVERSION=	0.7

PLIST_FILES=	bin/meek-client \
		bin/meek-server \
		man/man1/meek-client.1.gz \
		man/man1/meek-server.1.gz

SUB_FILES=	pkg-message

post-patch:
	@${MKDIR} ${WRKDIR}/src/git.torproject.org/pluggable-transports
	@${LN} -s ${WRKSRC} ${WRKDIR}/src/git.torproject.org/pluggable-transports/${PORTNAME}
	@${LN} -s ${WRKDIR}/goptlib-${GOPTLIBVERSION} ${WRKDIR}/src/git.torproject.org/pluggable-transports/goptlib.git

do-test:
.for t in ${GO_TARGET}
	cd ${GO_WRKSRC}; \
		${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} test ${GO_BUILDFLAGS} ${t}
.endfor

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/meek-server.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/meek-client.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
