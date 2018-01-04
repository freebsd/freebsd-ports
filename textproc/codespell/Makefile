# $FreeBSD$

PORTNAME=	codespell
PORTVERSION=	1.8
CATEGORIES=	textproc

MAINTAINER=	gjb@FreeBSD.org
COMMENT=	Source code spelling checker

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		python:3.4+

USE_GITHUB=	yes
GH_ACCOUNT=	lucasdemarchi
GH_TAGNAME=	4cb7fe3

OPTIONS_DEFINE=	DOCS EXAMPLES

PLIST_FILES=	bin/codespell
PORTDOCS=	NEWS TODO
PORTEXAMPLES=	*

NO_ARCH=	yes

SUB_FILES+=	pkg-message

do-build:
	@${REINPLACE_CMD} 's|#!/usr/bin/env python3|#!${PYTHON_CMD}|' \
		${WRKSRC}/codespell.py
	@${REINPLACE_CMD} "s|^default_dictionary = .*|default_dictionary = '${EXAMPLESDIR}/data/dictionary.txt'|" \
		${WRKSRC}/codespell.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/codespell.py ${STAGEDIR}${PREFIX}/bin/codespell

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
. for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
. endfor

do-install-EXAMPLES-on:
.for i in data example
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/${i}
	${INSTALL_DATA} ${WRKSRC}/${i}/* ${STAGEDIR}${EXAMPLESDIR}/${i}
.endfor

.include <bsd.port.mk>
