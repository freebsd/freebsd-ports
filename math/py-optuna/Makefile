PORTNAME=	optuna
DISTVERSION=	2.10.1
PORTREVISION=	1
CATEGORIES=	math # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nc@FreeBSD.org
COMMENT=	Hyperparameter optimization framework
WWW=		https://optuna.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Depends on expired databases/py-sqlalchemy12
EXPIRATION_DATE=2024-06-04

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}alembic14>0:databases/py-alembic14@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cliff>0:devel/py-cliff@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cmaes>0:math/py-cmaes@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorlog>0:devel/py-colorlog@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}joblib>0:devel/py-joblib@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy12>0:databases/py-sqlalchemy12@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>0:misc/py-tqdm@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
