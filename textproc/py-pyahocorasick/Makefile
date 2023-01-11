PORTNAME=	pyahocorasick
DISTVERSION=	1.4.4
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Python and C implementation of the Aho-Corasick algorithm
WWW=		https://github.com/WojciechMula/pyahocorasick

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.6+
USE_PYTHON=	distutils concurrent autoplist

PORTDOCS=	README.rst

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/ahocorasick*.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} unittests.py

.include <bsd.port.mk>
