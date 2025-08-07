PORTNAME=	trdsql
DISTVERSIONPREFIX=	v
DISTVERSION=	0.20.0
PORTREVISION=	9
CATEGORIES=	textproc

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Execute SQL queries on CSV, LTSV, JSON and TBLN
WWW=		https://github.com/noborus/trdsql

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/noborus/${PORTNAME}
GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "\
		-s -w \
		-X ${GO_MODULE}.Version=${DISTVERSIONFULL}"

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
