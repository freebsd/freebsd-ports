# Created by: Choe, Cheng-Dae
# $FreeBSD$

PORTNAME=	excelerator
PORTVERSION=	0.6.4.1
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	SF/py${PORTNAME}/pyExcelerator/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyexcelerator-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python library for generating Excel 97/2000/XP/2003 files

USES=		python:2 zip
USE_PYTHON=	distutils autoplist

DOCSDIR=	${PREFIX}/share/doc/py-excelerator
EXAMPLESDIR=	${PREFIX}/share/examples/py-excelerator
PORTDOCS=	*
PORTEXAMPLES=	*

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.bmp ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.py ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
