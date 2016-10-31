# $FreeBSD$

PORTNAME=	codespell
PORTVERSION=	1.6
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://packages.profusion.mobi/${PORTNAME}/ \
		https://www.glenbarber.us/ports/${CATEGORIES}/${PORTNAME}/

MAINTAINER=	gjb@FreeBSD.org
COMMENT=	Source code spelling checker

LICENSE=	GPLv2

USES=		python:3 tar:xz

OPTIONS_DEFINE=	DOCS EXAMPLES

PLIST_FILES=	bin/codespell
PORTDOCS=	COPYING README TODO
PORTEXAMPLES=	*

SUB_FILES+=	pkg-message

do-build:
	${REINPLACE_CMD} 's|#!/usr/bin/env python3|#!${PYTHON_CMD}|' \
		${WRKSRC}/codespell.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/codespell.py ${STAGEDIR}${PREFIX}/bin/codespell

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
. for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
. endfor

.for i in data example
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/${i}
	${INSTALL_DATA} ${WRKSRC}/${i}/* ${STAGEDIR}${EXAMPLESDIR}/${i}
.endfor

.include <bsd.port.mk>
