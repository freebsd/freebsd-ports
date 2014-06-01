# $FreeBSD$

PORTNAME=	codespell
PORTVERSION=	1.6
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://packages.profusion.mobi/${PORTNAME}/ \
		https://www.glenbarber.us/ports/${CATEGORIES}/${PORTNAME}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	gjb@FreeBSD.org
COMMENT=	Source code spelling checker

LICENSE=	GPLv2

USE_PYTHON=	3
USES=		tar:xz

OPTIONS_DEFINE=	DOCS EXAMPLES

PLIST_FILES=	bin/codespell
PORTDOCS=	COPYING README TODO
PORTEXAMPLES=	*

SUB_FILES+=	pkg-message

do-build:
	${REINPLACE_CMD} 's|#!/usr/bin/env python3|#!${LOCALBASE}/bin/${PYTHON_VERSION}|' \
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
