PORTNAME=	onionshare-cli
PORTVERSION=	2.7
CATEGORIES=	www security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	onionshare_cli-${PORTVERSION}

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Secure and anonymous file sharing via Tor (CLI version)
WWW=		https://onionshare.org

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=0:devel/py-poetry-core@${PY_FLAVOR}
# Upstream wants flask-compress>=1.24, but only Compress()/init_app is
# used and the tree's 1.14 provides it (files/patch-pyproject.toml relaxes
# the metadata to match)
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cepa>=1.8.4:net/py-cepa@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>=0:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}eventlet>=0:net/py-eventlet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask-Compress>=1.14:www/py-flask-compress@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask-socketio>=5.6:www/py-flask-socketio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask>=0:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gevent-websocket>=0:www/py-gevent-websocket@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gevent>=26.5.0:devel/py-gevent@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=24:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PyNaCl>=1.6.2:security/py-pynacl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysocks>=0:net/py-pysocks@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qrcode>=7.4.2:textproc/py-qrcode@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.32.3:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}unidecode>=0:converters/py-unidecode@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=2.7:net/py-urllib3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}waitress>=3.0.1:www/py-waitress@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}werkzeug>=3.1:www/py-werkzeug@${PY_FLAVOR} \
		meek-client:security/meek \
		obfs4proxy:security/obfs4proxy-tor \
		snowflake-client:security/snowflake-tor \
		tor:security/tor

USES=		cpe python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
