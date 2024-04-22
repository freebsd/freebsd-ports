PORTNAME=	sense2vec
PORTVERSION=	2.0.2
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Contextually-keyed word vectors
WWW=		https://github.com/explosion/sense2vec

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}catalogue>=2.0.1<2.1.0:devel/py-catalogue@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.15.0,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spacy>=3.0.0<4.0.0:textproc/py-spacy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}srsly>=2.4.0<3.0.0:devel/py-srsly@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wasabi>=0.8.1<1.2.0:textproc/py-wasabi@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
