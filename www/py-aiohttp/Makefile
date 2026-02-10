PORTNAME=	aiohttp
PORTVERSION=	3.13.3
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	PYPI \
		https://github.com/aio-libs/aiohttp/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Async http client/server framework (asyncio)
WWW=		https://docs.aiohttp.org/en/stable/ \
		https://github.com/aio-libs/aiohttp

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pkgconfig>=0,1:devel/py-pkgconfig@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=61.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libllhttp.so:www/llhttp
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohappyeyeballs>=2.5.0:net/py-aiohappyeyeballs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aiosignal>=1.4.0:devel/py-aiosignal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}attrs>=17.3.0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}frozenlist>=1.1.1:devel/py-frozenlist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}multidict>=4.5<7.0:www/py-multidict@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}propcache>=0.2.0:devel/py-propcache@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yarl>=1.17.0<2.0:www/py-yarl@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiodns>=3.3.0:dns/py-aiodns@${PY_FLAVOR} \
		${PY_BACKPORTS.ZSTD} \
		${PYTHON_PKGNAMEPREFIX}brotli>=1.2:archivers/py-brotli@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}freezegun>=0:devel/py-freezegun@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gunicorn>=0:www/py-gunicorn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}isal>=0:devel/py-isal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}proxy.py>=2.4.4:www/py-proxy.py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-codspeed>=0:devel/py-pytest-codspeed@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>=0:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=0,1:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}re-assert>=0:devel/py-re-assert@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uvloop>=0:devel/py-uvloop@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zlib-ng>=0:archivers/py-zlib-ng@${PY_FLAVOR}

USES=		cpe python
USE_PYTHON=	autoplist concurrent cython pep517 pytest

MAKE_ENV=	USE_SYSTEM_DEPS=1

CPE_VENDOR=	aiohttp_project

OPTIONS_DEFINE=	SPEEDUPS
SPEEDUPS_DESC=	Performance speedups

SPEEDUPS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiodns>=3.3.0:dns/py-aiodns@${PY_FLAVOR} \
			${PY_BACKPORTS.ZSTD} \
			${PYTHON_PKGNAMEPREFIX}brotli>=1.2:archivers/py-brotli@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31100
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}async_timeout>=4.0<6.0:devel/py-async_timeout@${PY_FLAVOR}
.endif

post-patch:
# Clean up bundled libraries
	@${RM} -r ${WRKSRC}/vendor/

post-install:
	${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.post.mk>
