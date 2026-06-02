PORTNAME=	nicegui
DISTVERSION=	3.12.1
CATEGORIES=	www graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT?=	Create web-based user interfaces with Python
WWW=		https://nicegui.io/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>0:devel/py-poetry-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}poetry-dynamic-versioning>=0:devel/py-poetry-dynamic-versioning@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiofiles>=0:devel/py-aiofiles@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aiohttp>=0:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certifi>=0:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docutils>=0:textproc/py-docutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fastapi>=0:www/py-fastapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h11>=0:net/py-h11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>=0:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}idna>=0:dns/py-idna@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ifaddr>=0:net/py-ifaddr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}itsdangerous>=0:security/py-itsdangerous@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml-html-clean>=0:devel/py-lxml-html-clean@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown2>=0:textproc/py-markdown2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}orjson>=0:devel/py-orjson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic-core>=0:devel/py-pydantic-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dotenv>=0:www/py-python-dotenv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-engineio>=0:devel/py-python-engineio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-multipart>=0:www/py-python-multipart@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-socketio>=0:devel/py-python-socketio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}starlette>=0:www/py-starlette@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tinycss2>=0:textproc/py-tinycss2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=0:net/py-urllib3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uvicorn>=0:www/py-uvicorn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}vbuild>=0:textproc/py-vbuild@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}watchfiles>=0:devel/py-watchfiles@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist pep517

SHEBANG_FILES=	nicegui/scripts/pack.py

CONFLICTS_INSTALL?=	www/py-nicegui-nogui

NO_ARCH=	yes

OPTIONS_DEFINE=			ALTAIR ANYWIDGET LIBSASS MATPLOTLIB PLOTLY \
				REDIS
OPTIONS_DEFAULT?=		ALTAIR ANYWIDGET LIBSASS MATPLOTLIB PLOTLY \
				PYWEBVIEW_QT REDIS
OPTIONS_RADIO=			PYWEBVIEW
OPTIONS_RADIO_PYWEBVIEW=	PYWEBVIEW_GTK PYWEBVIEW_QT

ALTAIR_DESC=		Enable support for altair
ANYWIDGET_DESC=		Enable support for anywidget
LIBSASS_DESC=		Enable support for libsass
MATPLOTLIB_DESC=	Enable support for matplotlib
PLOTLY_DESC=		Enable support for plotly
PYWEBVIEW_DESC=		Enable support for native mode
PYWEBVIEW_GTK_DESC=	Use GTK port
PYWEBVIEW_QT_DESC=	Use Qt port

ALTAIR_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}altair>=0:graphics/py-altair@${PY_FLAVOR}
ANYWIDGET_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}anywidget>=0:devel/py-anywidget@${PY_FLAVOR}
LIBSASS_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}libsass>=0:www/py-libsass@${PY_FLAVOR}
MATPLOTLIB_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}matplotlib>=0:math/py-matplotlib@${PY_FLAVOR}
PLOTLY_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}plotly>=0:graphics/py-plotly@${PY_FLAVOR}
PYWEBVIEW_GTK_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pywebview-gtk>=0:www/py-pywebview-gtk@${PY_FLAVOR}
PYWEBVIEW_QT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pywebview-qt>=0:www/py-pywebview-qt@${PY_FLAVOR}
REDIS_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}redis>=0:databases/py-redis@${PY_FLAVOR}

.include <bsd.port.mk>
