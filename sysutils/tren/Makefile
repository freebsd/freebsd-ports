# Created by: Tim Daneliuk <tren@tundraware.com>
# $FreeBSD$

PORTNAME=	tren
PORTVERSION=	1.242
CATEGORIES=	sysutils python
MASTER_SITES=	http://www.tundraware.com/Software/tren/

MAINTAINER=	tren@tundraware.com
COMMENT=	A Powerful File And Directory Batch Renaming Tool

USE_PYTHON=	yes

MAN1=		tren.1
MANCOMPRESSED=	yes

PLIST_FILES=	bin/tren.py
PORTDOCS=	WHATSNEW.txt tren-license.txt tren.html tren.pdf tren.ps tren.rst

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
