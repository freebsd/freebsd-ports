# $FreeBSD$

PORTNAME=	slack-term
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.2
CATEGORIES=	net-im

MAINTAINER=	dg@syrec.org
COMMENT=	Slack client for your terminal

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	go:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	erroneousboat
GH_SUBDIR=	src/github.com/${GH_ACCOUNT}/${PORTNAME}

SUB_FILES=	pkg-message
SUB_LIST=	PORTNAME=${PORTNAME}

PORTDOCS=	README.md

PLIST_FILES=	bin/slack-term

OPTIONS_DEFINE=	DOCS

do-build:
	@cd ${WRKSRC}/${GH_SUBDIR} && \
		${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} go build -o ${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
