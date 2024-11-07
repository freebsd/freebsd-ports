PORTNAME=	mido
DISTVERSION=	1.3.3
CATEGORIES=	multimedia python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	MIDI Objects for Python
WWW=		https://mido.readthedocs.io/ \
		https://github.com/mido/mido

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 concurrent autoplist pytest
NO_ARCH=	yes

# tests as of 1.3.3: 1 failed, 121 passed in 17.72s

.include <bsd.port.mk>
