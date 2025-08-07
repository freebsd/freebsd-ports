PORTNAME=	slack-term
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.0
PORTREVISION=	29
CATEGORIES=	net-im

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Slack client for your terminal
WWW=		https://github.com/erroneousboat/slack-term

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/erroneousboat/slack-term

SUB_FILES=	pkg-message
SUB_LIST=	PORTNAME=${PORTNAME}

PLIST_FILES=	bin/slack-term

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-patch:
	@cd ${WRKSRC}/vendor/github.com/OpenPeeDeeP/xdg && \
		${RLN} xdg_linux.go xdg_freebsd.go

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
