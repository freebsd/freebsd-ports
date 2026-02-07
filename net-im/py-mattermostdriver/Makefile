PORTNAME=	mattermostdriver
PORTVERSION=	7.3.2
PORTREVISION=	1
CATEGORIES=	net-im python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python Mattermost Driver
WWW=		https://vaelor.github.io/python-mattermost-driver/ \
		https://github.com/Vaelor/python-mattermost-driver

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.25:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}websockets>=8:devel/py-websockets@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
