# New ports collection makefile for:   pyweblib
# Date created:        22 March 2002
# Whom:                Oddbjorn Steffensen <oddbjorn@tricknology.org>
#
# $FreeBSD$
#

PORTNAME=	pyweblib
PORTVERSION=	1.3.7
CATEGORIES=	www
MASTER_SITES=	http://www.stroeder.com/pylib/PyWebLib/download/ \
		ftp://ftp.ipt.ru/pub/download/

MAINTAINER=	bsam@ipt.ru
COMMENT=	Yet another web programming framework for Python

LICENSE=	GPLv2

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

DOCS=		pydoc/pyweblib.forms.html \
		pydoc/pyweblib.helper.html \
		pydoc/pyweblib.html \
		pydoc/pyweblib.httphelper.html \
		pydoc/pyweblib.session.html \
		pydoc/pyweblib.sslenv.html

EXAMPLES=	*.py

post-install:
	${MKDIR} ${EXAMPLESDIR} ${EXAMPLESDIR}/cgi-bin
	${INSTALL_DATA} ${WRKSRC}/cgi-bin/${EXAMPLES} ${EXAMPLESDIR}/cgi-bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/pydoc
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/htdocs/${file} ${DOCSDIR}/${file}
.endfor
.endif

.include <bsd.port.mk>
