PORTNAME=	pywry
DISTVERSION=	2.0.6
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lightweight cross-platform WebView engine and UI toolkit for Python
WWW=		https://deeleeramone.github.io/PyWry/ \
		https://github.com/deeleeramone/PyWry

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=1.21.0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytauri-wheel>=0.8.0:www/py-pytauri-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libwebkit2gtk-4.1.so:www/webkit2-gtk@41 \
		libjavascriptcoregtk-4.1.so:www/webkit2-gtk@41 \
		libsoup-3.0.so:devel/libsoup3
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytauri>=0.8.0:www/py-pytauri@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}anyio>=4.0.0:devel/py-anyio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>=0.27.0:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.0.0:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic-settings>=2.0.0:devel/py-pydantic-settings@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}redis>=7.1.0:databases/py-redis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fastapi>=0.128.0:www/py-fastapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uvicorn>=0.40.0:www/py-uvicorn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}watchdog>=3.0.0:devel/py-watchdog@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setproctitle>=1.3.0:devel/py-setproctitle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}websockets>=15.0.0:devel/py-websockets@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=7:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytauri-wheel>=0.8.0:www/py-pytauri-wheel@${PY_FLAVOR}

USES=		gnome python
USE_PYTHON=	pep517 autoplist
USE_GNOME=	cairo gdkpixbuf glib20 gtk30

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${WRKSRC}
TEST_WRKDIR=	${WRKSRC}/tests
TEST_ARGS=	--disable-plugin-autoload

post-extract:
	@${MKDIR} ${WRKSRC}/tests
	@${CP} ${FILESDIR}/test_smoke.py ${WRKSRC}/tests/

# tests as of 2.0.6: 2 passed in 0.53s

.include <bsd.port.mk>
