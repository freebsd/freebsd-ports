PORTNAME=	sparqlwrapper
PORTVERSION=	2.0.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	SPARQLWrapper-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	SPARQL endpoint interface to Python
WWW=		https://sparqlwrapper.readthedocs.io/en/stable/

LICENSE=	W3C
LICENSE_NAME=	W3C Software Notice and License
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}rdflib>=6.1.1:textproc/py-rdflib@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
