PORTNAME=	meek
DISTVERSIONPREFIX=v
DISTVERSION=	0.37.0
PORTREVISION=	25
CATEGORIES=	security net

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Pluggable transport proxy that relays through third-party server
WWW=		https://trac.torproject.org/projects/tor/wiki/doc/meek

LICENSE=	CC0-1.0
LICENSE_FILE=	${WRKSRC}/${GO_PKGNAME}/COPYING

USES=		cpe go:modules
USE_GITHUB=	yes

CPE_VENDOR=	torproject

GO_BUILDFLAGS+=	-ldflags '-s -w'
GO_PKGNAME=	git.torproject.org/pluggable-transports/meek.git
GO_TARGET=	./meek-client ./meek-server

GH_ACCOUNT=	torbsd
GH_SUBDIR=	${GO_PKGNAME}
GH_TUPLE=	torbsd:goptlib:v1.2.0:torbsd_goptlib/vendor/git.torproject.org/pluggable-transports/goptlib.git \
		golang:crypto:86341886e292:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:27dd8689420f:golang_net/vendor/golang.org/x/net \
		golang:sys:4e6760a101f9:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.7:golang_text/vendor/golang.org/x/text \
		refraction-networking:utls:v1.0.0:refraction_networking_utls/vendor/github.com/refraction-networking/utls

PLIST_FILES=	bin/meek-client \
		bin/meek-server \
		share/man/man1/meek-client.1.gz \
		share/man/man1/meek-server.1.gz

SUB_FILES=	pkg-message

PORTSCOUT=	skipv:rm

do-test:
.for t in ${GO_TARGET}
	cd ${GO_WRKSRC}; \
		${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} test ${GO_BUILDFLAGS} ${t}
.endfor

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/meek-server.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/meek-client.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
