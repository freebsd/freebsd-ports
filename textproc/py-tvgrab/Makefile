# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	TVGrab
PORTVERSION=	0.5.1
PORTREVISION=	3
CATEGORIES=	textproc python
MASTER_SITES=	SF/py${PORTNAME:tl}/lib/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pytvgrab-lib-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library to write grabbers of tv scheduling collections

USES=		python:2 tar:bzip2
USE_PYTHON=	distutils autoplist

PORTDOCS=	README

post-extract:
	@${CP} ${FILESDIR}/timezone.py ${WRKSRC}/lib/timezone.py

post-patch:
	@${REINPLACE_CMD} -e 's,python -c,${PYTHON_CMD} -c,' ${WRKSRC}/setup.py

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
