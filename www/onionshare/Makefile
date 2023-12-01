PORTNAME=	onionshare
DISTVERSIONPREFIX=v
DISTVERSION=	2.6
PORTREVISION=	2
CATEGORIES=	www security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Secure and anonymous file sharing via Tor
WWW=		https://onionshare.org

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	meek-client:security/meek \
		obfs4proxy:security/obfs4proxy-tor \
		snowflake-client:security/snowflake-tor \
		tor:security/tor \
		${PYTHON_PKGNAMEPREFIX}Flask-HTTPAuth>=0:security/py-flask-httpauth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask>=0:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}atomicwrites>=0:devel/py-atomicwrites@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cepa>=0:net/py-cepa@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certifi>=0:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>=0:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}eventlet>=0:net/py-eventlet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask-socketio>=0:www/py-flask-socketio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gevent-websocket>=0:www/py-gevent-websocket@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}onionshare-cli>=0:www/onionshare-cli@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycryptodome>=0:security/py-pycryptodome@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pynacl>=0:security/py-pynacl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyside2>=0:devel/pyside2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysocks>=0:net/py-pysocks@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qrcode>=0:textproc/py-qrcode@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}shiboken2>=0:devel/shiboken2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}unidecode>=0:converters/py-unidecode@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=0:net/py-urllib3@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-qt>=0:devel/py-pytest-qt@${PY_FLAVOR}

USES=		cpe python pyqt:5 qt:5 shebangfix xorg
USE_GITHUB=	yes
USE_PYQT=	pyqt5 sip
USE_PYTHON=	distutils autoplist
USE_XORG=	x11 xcb

PYSETUP=	${WRKSRC}/desktop/setup.py
SHEBANG_FILES=	${WRKSRC}/cli/*.py \
		${WRKSRC}/cli/onionshare_cli/*.py \
		${WRKSRC}/cli/tests/*.py \
		${WRKSRC}/desktop/*.py \
		${WRKSRC}/desktop/scripts/*.py \
		${WRKSRC}/desktop/tests/*.py

post-patch:
	${RLN} ${WRKSRC}/cli/onionshare_cli ${WRKSRC}/onionshare-cli
	${RLN} ${WRKSRC}/desktop/onionshare ${WRKSRC}/onionshare
	${REINPLACE_CMD} 's|"onionshare-cli = onionshare_cli:main",||' ${PYSETUP}
	${RM} ${WRKSRC}/desktop/package/onionshare-cli.py

# https://github.com/onionshare/onionshare/blob/main/desktop/tests/run.sh
do-test:
	cd ${WRKSRC}/desktop \
	&& ${PYTHON_CMD} -m pytest -v tests/test_gui_tabs.py \
	&& ${PYTHON_CMD} -m pytest -v tests/test_gui_share.py \
	&& ${PYTHON_CMD} -m pytest -v tests/test_gui_receive.py \
	&& ${PYTHON_CMD} -m pytest -v tests/test_gui_website.py \
	&& ${PYTHON_CMD} -m pytest -v tests/test_gui_chat.py

.include <bsd.port.mk>
