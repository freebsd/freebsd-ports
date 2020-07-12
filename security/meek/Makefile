# $FreeBSD$

PORTNAME=	meek
DISTVERSION=	0.35.0
CATEGORIES=	security
MASTER_SITES=	https://gitweb.torproject.org/pluggable-transports/meek.git/snapshot/ \
DISTFILES=	${PORTNAME}-v${DISTVERSION}.tar.gz \

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Pluggable transport proxy that relays through third-party server

LICENSE=	CC0-1.0
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN=		go: git.torproject.org/pluggable-transports/goptlib.git@v1.1.0: Get "https://proxy.golang.org/git.torproject.org/pluggable-transports/goptlib.git/@v/v1.1.0.mod": dial tcp 172.217.17.113:443: connect: can't assign requested address

USES=		go

GO_TARGET=	./meek-client \
		./meek-server
GH_TUPLE=	\
		golang:crypto:4b2356b1ed79:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:ff2c4b7c35a0:golang_net/vendor/golang.org/x/net \
		golang:sys:593003d681fa:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.0:golang_text/vendor/golang.org/x/text \
		refraction-networking:utls:43c36d3c1f57:refraction_networking_utls/vendor/github.com/refraction-networking/utls

PLIST_FILES=	bin/meek-client \
		bin/meek-server \
		man/man1/meek-client.1.gz \
		man/man1/meek-server.1.gz

SUB_FILES=	pkg-message

post-patch:
	@${MKDIR} ${WRKDIR}/src/git.torproject.org/pluggable-transports
	@${LN} -s ${WRKSRC} ${WRKDIR}/src/git.torproject.org/pluggable-transports/${PORTNAME}

do-test:
.for t in ${GO_TARGET}
	cd ${GO_WRKSRC}; \
		${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} test ${GO_BUILDFLAGS} ${t}
.endfor

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/meek-server.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/meek-client.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
