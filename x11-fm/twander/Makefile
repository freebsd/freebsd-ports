# Created by: tundra
# $FreeBSD$

PORTNAME=	twander
PORTVERSION=	3.231
PORTREVISION=	1
CATEGORIES=	x11-fm
MASTER_SITES=	http://www.tundraware.com/Software/twander/

MAINTAINER=	twander@tundraware.com
COMMENT=	Better Filesystem Browser

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>0:x11-toolkits/py-tkinter
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>0:x11-toolkits/py-tkinter

USES=		python
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} \
		-e 's|/usr/bin/env python|${PYTHON_CMD}|' \
		${WRKSRC}/twander.py
	@${REINPLACE_CMD} \
		-e 's|python |${PYTHON_CMD} |' \
		${WRKSRC}/Makefile

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in READ-1ST.txt WHATSNEW.txt .twander twander-license.txt twander.html twander.pdf twander.ps twander.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
