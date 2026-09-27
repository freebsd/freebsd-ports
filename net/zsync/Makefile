PORTNAME=	zsync
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.0
CATEGORIES=	net

MAINTAINER=	chris.longros@gmail.com
COMMENT=	File transfer program
WWW=		https://github.com/cph6/zsync

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_MODULE=	github.com/cph6/zsync
GO_TARGET=	./cmd/zsync \
		./cmd/zsyncmake

TESTING_UNSAFE=	Requires Apache webserver running, recursive directory problems

PLIST_FILES=	bin/zsync \
		bin/zsyncmake \
		share/man/man1/zsync.1.gz \
		share/man/man1/zsyncmake.1.gz
PORTDOCS=	NEWS README.md

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/zsync.1 ${WRKSRC}/man/zsyncmake.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
