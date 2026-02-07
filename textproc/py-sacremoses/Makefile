PORTNAME=	sacremoses
DISTVERSION=	0.1.1
CATEGORIES=	textproc python # machine-learning
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python port of Moses tokenizer, truecaser and normalizer
WWW=		https://github.com/hplt-project/sacremoses

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=7.1.2:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}joblib>=1.1.0:devel/py-joblib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}regex>=2020.1.8:textproc/py-regex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.64.0:misc/py-tqdm@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	hplt-project

NO_ARCH=	yes

# tests as of 0.1.1: 1 failed, 35 passed, 1 skipped in 15.70s, see https://github.com/hplt-project/sacremoses/issues/153

.include <bsd.port.mk>
