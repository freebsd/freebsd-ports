# ex:ts=8
# Ports collection makefile for:	pdfmap
# Date created:			Mar 24, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	pdfmap
PORTVERSION=	2.00
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generate maps in PDF format and place clickable objects on them

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/jaxml.py:${PORTSDIR}/textproc/py-jaxml \
		${PYTHON_SITELIBDIR}/PIL/Image.py:${PORTSDIR}/graphics/py-imaging
BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/reportlab/pdfgen/canvas.py:${PORTSDIR}/print/py-reportlab \
		${PYTHON_SITELIBDIR}/PIL/Image.py:${PORTSDIR}/graphics/py-imaging

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

DOCS=		CREDITS NEWS README TODO doc/*.html

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
