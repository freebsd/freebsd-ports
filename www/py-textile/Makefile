PORTNAME=	textile
DISTVERSION=	4.0.3
PORTREVISION=	1
CATEGORIES=	www textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Textile markup generator written in Python
WWW=		https://github.com/textile/python-textile/releases

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nh3>=0:www/py-nh3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=2.8:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=2.5:devel/py-pytest-cov@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	IMAGESIZE
OPTIONS_DEFAULT=IMAGESIZE

IMAGESIZE_DESC=	Enable image size support

IMAGESIZE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>=3.0.0:graphics/py-pillow@${PY_FLAVOR}

.include <bsd.port.mk>
