PORTNAME=	flask-apscheduler
PORTVERSION=	1.13.1
PORTREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	PYPI \
		https://github.com/viniciuschiele/flask-apscheduler/releases/download/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Flask-APScheduler-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	APScheduler support for Flask
WWW=		https://github.com/viniciuschiele/flask-apscheduler

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}apscheduler>=3.2.0<4.0.0:devel/py-apscheduler@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask>=2.2.5<4.0.0:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>=2.4.2:devel/py-python-dateutil@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
