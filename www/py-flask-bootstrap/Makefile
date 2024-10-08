PORTNAME=	Flask-Bootstrap
PORTVERSION=	3.3.7.1
PORTREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Include Bootstrap in your project, without any boilerplate code
WWW=		https://github.com/mbr/flask-bootstrap

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dominate>=0:textproc/py-dominate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask>=0.8:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}visitor>=0:devel/py-visitor@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}Bootstrap-Flask

NO_ARCH=	yes

.include <bsd.port.mk>
