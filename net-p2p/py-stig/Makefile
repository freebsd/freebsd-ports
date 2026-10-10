PORTNAME=	stig
DISTVERSION=	0.15.0a0
CATEGORIES=	net-p2p
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	alven@FreeBSD.org
COMMENT=	TUI and CLI client for the BitTorrent Transmission daemon
WWW=		https://github.com/rndusr/stig/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp-socks>0:net/py-aiohttp-socks@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}async_timeout>0:devel/py-async_timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bidict>0:devel/py-bidict@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}blinker>0:devel/py-blinker@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}natsort>0:devel/py-natsort@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyxdg>0:devel/py-pyxdg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setproctitle>0:devel/py-setproctitle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urwidtrees>0:devel/py-urwidtrees@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wcwidth>0:devel/py-wcwidth@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asynctest>0:devel/py-asynctest@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517 pytest

TESTING_UNSAFE=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
