# Created by: Tim Daneliuk <tren@tundraware.com>
# $FreeBSD$

PORTNAME=	tren
PORTVERSION=	1.242
CATEGORIES=	sysutils python
MASTER_SITES=	http://www.tundraware.com/Software/tren/

MAINTAINER=	tren@tundraware.com
COMMENT=	Powerful File And Directory Batch Renaming Tool

USES=		python
PLIST_FILES=	bin/tren.py man/man1/tren.1.gz
PORTDOCS=	WHATSNEW.txt tren-license.txt tren.html tren.pdf tren.ps tren.rst
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
