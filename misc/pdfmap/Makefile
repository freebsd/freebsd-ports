# ex:ts=8
# Ports collection makefile for:	pdfmap
# Date created:			Mar 24, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	pdfmap
PORTVERSION=	1.50
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/jaxml.py:${PORTSDIR}/textproc/py-jaxml \
		${PYTHON_SITELIBDIR}/reportlab/pdfgen/canvas.py:${PORTSDIR}/print/py-reportlab \
		${PYTHON_SITELIBDIR}/PIL/Image.py:${PORTSDIR}/graphics/py-imaging

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

post-install:
	@${MV} -f ${PREFIX}/bin/pdfmap.py ${PREFIX}/bin/pdfmap
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/ ${DOCSDIR}
.endif

.include <bsd.port.mk>
