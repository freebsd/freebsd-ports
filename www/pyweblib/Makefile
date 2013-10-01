# Created by: Oddbjorn Steffensen <oddbjorn@tricknology.org>
# $FreeBSD$

PORTNAME=	pyweblib
PORTVERSION=	1.3.10
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.stroeder.com/pylib/PyWebLib/download/

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Yet another web programming framework for Python

LICENSE=	GPLv2

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

PORTDOCS=	pyweblib.forms.html pyweblib.helper.html \
		pyweblib.html pyweblib.httphelper.html \
		pyweblib.session.html pyweblib.sslenv.html
EXAMPLES=	*.py

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/cgi-bin ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/cgi-bin/${EXAMPLES} ${STAGEDIR}${EXAMPLESDIR}/cgi-bin
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/htdocs/pydoc/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
