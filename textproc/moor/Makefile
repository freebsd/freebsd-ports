PORTNAME=	moor
DISTVERSIONPREFIX=	v
DISTVERSION=	2.9.4
CATEGORIES=	textproc

MAINTAINER=	nxjoseph@protonmail.com
COMMENT=	Pager designed to do the right thing without any configuration
WWW=		https://github.com/walles/moor

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/walles/${PORTNAME}/v2
GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags="-s -w -X main.versionString=${DISTVERSIONFULL}"

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz
PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES
OPTIONS_SUB=	yes

post-extract:
	@cd ${WRKSRC}/sample-files && \
		${LN} -s compressed.txt.zst compressed.txt.zstd

post-patch:
	@${REINPLACE_CMD} -e '22s,".*","${WRKSRC}/sample-files",g' \
		${WRKSRC}/internal/reader/reader_test.go

post-install:
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 \
		${STAGEDIR}${MANDIRS}/man1

post-install-EXAMPLES-on:
	@cd ${WRKSRC}/sample-files && \
		${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
