PORTNAME=	tidemail
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.1
CATEGORIES=	mail

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Modern TUI email client: IMAP/SMTP, Gmail/Outlook OAuth, and more
WWW=		https://github.com/allisonhere/tidemail

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	bash:shells/bash

USES=		go:modules
GO_MODULE=	github.com/allisonhere/tidemail

PLIST_FILES=	bin/tidemail \
		share/man/man1/tidemail.1.gz
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/tidemail.1 ${STAGEDIR}${PREFIX}/share/man/man1

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} '*.md' ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
