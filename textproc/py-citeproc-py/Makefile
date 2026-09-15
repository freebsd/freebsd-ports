PORTNAME=	citeproc-py
DISTVERSION=	0.11.1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	citeproc_py-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Citation Style Language (CSL) processor for Python
WWW=		https://github.com/brechtm/citeproc-py

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rnc2rng>=2.6.1:textproc/py-rnc2rng@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=63:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}versioneer>0:devel/py-versioneer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 concurrent autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
