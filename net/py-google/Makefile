# Created by: Hye-Shik Chang <perky@fallin.lv>
# $FreeBSD$

PORTNAME=	google
PORTVERSION=	0.6
CATEGORIES=	net python
MASTER_SITES=	SF/py${PORTNAME}/py${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pygoogle-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python wrapper for the Google web API

RUN_DEPENDS=	${PYXML}

USES=		python
USE_PYTHON=	distutils autoplist

PORTDOCS=	*
DOCSDIR=	${PREFIX}/share/doc/py-google
PORTEXAMPLES=	*
EXAMPLESDIR=	${PREFIX}/share/examples/py-google

post-patch:
# www/py-websvcs has an incompatible version of SOAP.py
	@${MV} ${WRKSRC}/SOAP.py ${WRKSRC}/SOAPgoogle.py
	@cd ${WRKSRC}; for f in *.py; do \
		${REINPLACE_CMD} -e 's,import SOAP,import SOAPgoogle as SOAP,g' $$f; \
	done
	@${MKDIR} ${WRKSRC}/tests
	@${MV} ${WRKSRC}/*test*.py ${WRKSRC}/tests
	@${REINPLACE_CMD} -e 's,.*extra_path.*,,g' ${WRKSRC}/setup.py

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/tests/*.py ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
