PORTNAME=	docling-demo
DISTVERSION=	0.1.1
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Demo application for Docling with Azure AI Search
WWW=		https://pypi.org/project/docling-demo/

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}azure-identity>=0:devel/py-azure-identity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-search-documents>0:devel/py-azure-search-documents@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}build>=1.3.0:devel/py-build@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docling>=2.64.0:textproc/py-docling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hf-xet>=1.2.0:misc/py-hf-xet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}langchain>=1.1.2:misc/py-langchain@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}langchain-docling>=2.0.0:textproc/py-langchain-docling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}langchain-openai>=1.1.0:misc/py-langchain-openai@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}onnxruntime>=1.23.2:misc/py-onnxruntime@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymupdf>=1.26.6:print/py-PyMuPDF@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}transformers>=4.57.3:misc/py-transformers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}twine>=6.2.0:devel/py-twine@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
