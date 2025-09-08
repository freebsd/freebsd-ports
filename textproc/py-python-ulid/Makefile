PORTNAME=	python-ulid
PORTVERSION=	3.1.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python_ulid-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Universally unique lexicographically sortable identifier
WWW=		https://python-ulid.readthedocs.io/en/latest/ \
		https://github.com/mdomke/python-ulid

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-fancy-pypi-readme>=0:devel/py-hatch-fancy-pypi-readme@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatch-vcs>=0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}

USES=		python:3.9+
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	PYDANTIC
PYDANTIC_DESC=	Pydantic support

PYDANTIC_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pydantic2>=2.0:devel/py-pydantic2@${PY_FLAVOR}

.include <bsd.port.mk>
