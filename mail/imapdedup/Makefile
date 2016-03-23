# $FreeBSD$

PORTNAME=	imapdedup
PORTVERSION=	0.0.20150331
CATEGORIES=	mail

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Duplicate email message remover

LICENSE=	GPLv2

USES=		python:run shebangfix
SHEBANG_FILES=	imapdedup.py
USE_GITHUB=	yes
GH_PROJECT=	IMAPdedup
GH_ACCOUNT=	quentinsf
GH_TAGNAME=	711c851
NO_BUILD=	yes
PLIST_FILES=	bin/imapdedup.py
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/imapdedup.py ${STAGEDIR}${PREFIX}/bin

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
