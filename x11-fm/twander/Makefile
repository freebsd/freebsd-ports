# New ports collection makefile for:	twander
# Date Created:				17 February 2003
# Whom:					tundra
#
# $FreeBSD$
#

PORTNAME=	twander
PORTVERSION=	3.231
CATEGORIES=	x11-fm
MASTER_SITES=	http://www.tundraware.com/Software/twander/

MAINTAINER=	twander@tundraware.com
COMMENT=	A Better Filesystem Browser

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter

USE_PYTHON=	yes

MANCOMPRESSED=	yes
MAN1=		twander.1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in READ-1ST.txt WHATSNEW.txt .twander twander-license.txt twander.html twander.pdf twander.ps twander.txt
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
