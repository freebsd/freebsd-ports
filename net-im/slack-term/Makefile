# $FreeBSD$

PORTNAME=	slack-term
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.1
CATEGORIES=	net-im

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Slack client for your terminal

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	erroneousboat
GH_SUBDIR=	src/github.com/${GH_ACCOUNT}/${PORTNAME}

SUB_FILES=	pkg-message
SUB_LIST=	PORTNAME=${PORTNAME}

PORTDOCS=	README.md

PLIST_FILES=	bin/slack-term

OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
