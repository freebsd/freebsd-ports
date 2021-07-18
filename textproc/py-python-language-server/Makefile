# Created by: Rainer Hurling <rhurlin@gwdg.de>

PORTNAME=	python-language-server
PORTVERSION=	0.36.2
PORTREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rhurlin@FreeBSD.org
COMMENT=	Python implementation of the Language Server Protocol

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Upstream forked and replaced by py-python-lsp-server
EXPIRATION_DATE=	2021-07-31

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}autopep8>0:textproc/py-autopep8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jedi>0:devel/py-jedi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mccabe>0:devel/py-mccabe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pluggy>0:devel/py-pluggy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycodestyle>0:devel/py-pycodestyle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydocstyle>0:devel/py-pydocstyle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyflakes>0:devel/py-pyflakes@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-jsonrpc-server>0:devel/py-python-jsonrpc-server@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rope>0:devel/py-rope@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ujson>0:devel/py-ujson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yapf>0:textproc/py-yapf@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

# Until upstream is merged, do it here
# https://github.com/palantir/python-language-server/pull/918
post-patch:
	@${REINPLACE_CMD} -e 's|<0.18.0,||g' \
		${WRKSRC}/python_language_server.egg-info/requires.txt
	@${REINPLACE_CMD} -e 's|,<0.18.0||g' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
