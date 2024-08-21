PORTNAME=	fasttext-predict
DISTVERSION=	0.9.2.2
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	DtxdF@disroot.org
COMMENT=	Python package for fasttext
WWW=		https://pypi.org/project/${PORTNAME} \
		https://github.com/searxng/${PORTNAME}

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pybind11>=0:devel/py-pybind11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/fasttext_pybind.cpython-${PYTHON_VER:S/.//}.so

.include <bsd.port.mk>
