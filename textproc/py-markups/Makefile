PORTNAME=	markups
PORTVERSION=	4.1.1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Wrapper around various text markup languages
WWW=		https://pymarkups.readthedocs.io/en/latest/ \
		https://github.com/retext-project/pymarkups

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.2:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
TEST_DEPENDS=	asciidoc>=0:textproc/asciidoc \
		${PYTHON_PKGNAMEPREFIX}docutils>=0,1:textproc/py-docutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown>=3:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymdown-extensions>=0:textproc/py-pymdown-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}textile>=0:www/py-textile@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 unittest

NO_ARCH=	yes

OPTIONS_DEFINE=	ASCIIDOC HIGHLIGHTING MARKDOWN RESTRUCTUREDTEXT TEXTILE
ASCIIDOC_DESC=		AsciiDoc support
HIGHLIGHTING_DESC=	Highlighting support
MARKDOWN_DESC=		Markdown support
RESTRUCTUREDTEXT_DESC=	reStructuredText (reST) support
TEXTILE_DESC=		Textile support

ASCIIDOC_RUN_DEPENDS=	asciidoc:textproc/asciidoc \
			${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml@${PY_FLAVOR}
HIGHLIGHTING_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygments>=0:textproc/py-pygments@${PY_FLAVOR} \
MARKDOWN_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}markdown>=3:textproc/py-markdown@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}python-markdown-math>=0:textproc/py-python-markdown-math@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR}
RESTRUCTUREDTEXT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docutils>=0,1:textproc/py-docutils@${PY_FLAVOR}
TEXTILE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}textile>=0:www/py-textile@${PY_FLAVOR}

.include <bsd.port.mk>
