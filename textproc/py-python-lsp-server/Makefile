# Created by: Rainer Hurling <rhurlin@gwdg.de>

PORTNAME=	python-lsp-server
PORTVERSION=	1.1.0
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rhurlin@FreeBSD.org
COMMENT=	Python implementation of the Language Server Protocol

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}autopep8>0:textproc/py-autopep8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flake8>=0:devel/py-flake8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jedi>0:devel/py-jedi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mccabe>0:devel/py-mccabe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pluggy>0:devel/py-pluggy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycodestyle>0:devel/py-pycodestyle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydocstyle>0:devel/py-pydocstyle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyflakes>0:devel/py-pyflakes@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyls-black>0:devel/py-pyls-black@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-lsp-jsonrpc>0:textproc/py-python-lsp-jsonrpc@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ujson>0:devel/py-ujson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yapf>0:textproc/py-yapf@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

test:
	cd ${WRKSRC} && \
	    ${SETENV} PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR} \
	    ${LOCALBASE}/bin/pytest

.include <bsd.port.mk>
