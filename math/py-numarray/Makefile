# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	numarray
PORTVERSION=	1.5.2
CATEGORIES=	math python
MASTER_SITES=	SF/numpy/Old%20Numarray/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Numeric array manipulation extension module for Python

USES=		python
USE_PYTHON=	distutils autoplist

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-configure:
	cd ${WRKSRC} && \
	${PYTHON_CMD} generate.py && \
	${PYTHON_CMD} Include/numarray/genapis.py

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${TAR} -C ${WRKSRC}/Doc -cf- .|${TAR} -C ${STAGEDIR}${DOCSDIR} -xf-
	@${TAR} -C ${WRKSRC}/Examples -cf- .|${TAR} -C ${STAGEDIR}${EXAMPLESDIR} -xf-
	@${RM} -fr ${STAGEDIR}${EXAMPLESDIR}/ufunc/build

.include <bsd.port.mk>
