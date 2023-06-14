PORTNAME=	flask-apscheduler
PORTVERSION=	1.12.4
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Flask-APScheduler-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	APScheduler support for Flask
WWW=		https://github.com/viniciuschiele/flask-apscheduler

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}apscheduler>=3.2.0<4.0.0:devel/py-apscheduler@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask>=0.10.1:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.4.2:devel/py-dateutil@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
