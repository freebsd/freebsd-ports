PORTNAME=	cinemagoer
PORTVERSION=	2026.8.20
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python package to access the IMDb database
WWW=		https://cinemagoer.github.io/ \
		https://github.com/cinemagoer/cinemagoer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=6.1.1:devel/py-lxml@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-cov>=6.1.1:devel/py-pytest-cov@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

OPTIONS_DEFINE=	SQLALCHEMY
SQLALCHEMY_DESC=SQLAlchemy support

SQLALCHEMY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy20>=2.0.50<2.1:databases/py-sqlalchemy20@${PY_FLAVOR}

.include <bsd.port.mk>
