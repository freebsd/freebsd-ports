# Created by: Alan Eldridge <alane@FreeBSD.org>
# $FreeBSD$

PORTNAME=	txt2tags
PORTVERSION=	3.6
CATEGORIES=	textproc

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Convert simply formatted text into markup (e.g., HTML)

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		python:3.6+ shebangfix
SHEBANG_FILES=	txt2tags.py
USE_GITHUB=	yes
NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/txt2tags.py ${STAGEDIR}${PREFIX}/bin/txt2tags

do-install-EXAMPLES-on:
	@cd ${WRKSRC}/samples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} extras ${STAGEDIR}${EXAMPLESDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG.md ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
.for doc in markup rules userguide
	@cd ${WRKSRC}/docs/${doc} && ${WRKSRC}/txt2tags.py ${doc}.t2t
	${INSTALL_DATA} ${WRKSRC}/docs/${doc}/${doc}.html ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
