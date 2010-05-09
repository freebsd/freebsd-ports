# New ports collection makefile for: tren
# Date created:        23 April 2010
# Whom: Tim Daneliuk <tren@tundraware.com>
#
# $FreeBSD$
#

PORTNAME=	tren
PORTVERSION=	1.217
CATEGORIES=	sysutils python
MASTER_SITES=	http://www.tundraware.com/Software/tren/

MAINTAINER=	tren@tundraware.com
COMMENT=	A Powerful File And Directory Batch Renaming Tool

USE_PYTHON=	yes

MAN1=		tren.1
MANCOMPRESSED=	yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in WHATSNEW.txt tren-license.txt tren.html tren.pdf tren.ps tren.rst
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
