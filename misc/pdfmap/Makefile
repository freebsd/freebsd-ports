# ex:ts=8
# Ports collection makefile for:	pdfmap
# Date created:			Mar 24, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	pdfmap
PORTVERSION=	1.60
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generate maps in PDF format and place clickable objects on them

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/jaxml.py:${PORTSDIR}/textproc/py-jaxml \
		${PYTHON_SITELIBDIR}/PIL/Image.py:${PORTSDIR}/graphics/py-imaging
BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/reportlab/pdfgen/canvas.py:${PORTSDIR}/print/py-reportlab \
		${PYTHON_SITELIBDIR}/PIL/Image.py:${PORTSDIR}/graphics/py-imaging

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

DOCS=		CREDITS NEWS README TODO doc/*.html

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pdfmap.py ${PREFIX}/bin/pdfmap
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
