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

USES=		go

GO_TARGET=	./meek-client \
		./meek-server

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
