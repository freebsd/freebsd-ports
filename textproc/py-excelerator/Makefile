# Created by: Choe, Cheng-Dae
# $FreeBSD$

PORTNAME=	excelerator
PORTVERSION=	0.6.4.1
PORTREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	SF/py${PORTNAME}/pyExcelerator/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyexcelerator-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python library for generating Excel 97/2000/XP/2003 files

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

OPTIONS_DEFINE=	DOCS EXAMPLES

USES=		python:2.7 zip
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

DOCSDIR=	${PREFIX}/share/doc/py-excelerator
EXAMPLESDIR=	${PREFIX}/share/examples/py-excelerator
PORTDOCS=	*
PORTEXAMPLES=	*

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.bmp ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.py ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
