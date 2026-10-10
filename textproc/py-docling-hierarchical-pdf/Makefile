PORTNAME=	docling-hierarchical-pdf
DISTVERSION=	0.1.9
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Inference of header hierarchy in the Docling PDF parsing pipeline
WWW=		https://krrome.github.io/docling-hierarchical-pdf/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docling>=2.53.0:textproc/py-docling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.19.5:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymupdf>=1.26.4:print/py-PyMuPDF@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-learn>=1.6.0:science/py-scikit-learn@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
