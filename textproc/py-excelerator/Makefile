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

USES=		zip
USE_PYTHON=	2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

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
