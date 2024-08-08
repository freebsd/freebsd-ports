PORTNAME=	slackeventsapi
PORTVERSION=	3.0.2
CATEGORIES=	net-im python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python Slack Events API adapter for Flask
WWW=		https://github.com/slackapi/python-slack-events-api

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flask>=2<4:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyee>=8:devel/py-pyee@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
