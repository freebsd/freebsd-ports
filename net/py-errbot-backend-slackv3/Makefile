PORTNAME=	errbot-backend-slackv3
PORTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Errbot SlackV3 backend plugin
WWW=		https://err-backend-slackv3.readthedocs.io/en/latest/ \
		https://github.com/errbotio/err-backend-slackv3

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=0:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown>=3.3.6:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}slack-sdk>=3.12.0:net-im/py-slack-sdk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}slackeventsapi>=3.0.0:net-im/py-slackeventsapi@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
