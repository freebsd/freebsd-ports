PORTNAME=	aeidon
PORTVERSION=	2.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Reading, write and manipulate text-based subtitle files
WWW=		https://github.com/otsaloma/gaupol

LICENSE=	GPLv3+

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=1.27:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}charset-normalizer>=2.0:textproc/py-charset-normalizer@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
