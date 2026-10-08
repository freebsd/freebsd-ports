PORTNAME=	streamlink
DISTVERSION=	8.6.2
CATEGORIES=	multimedia
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	takefu@airport.fm
COMMENT=	Command-line utility that pipes video streams
WWW=		https://streamlink.github.io/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS}\
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}certifi>0:security/py-certifi@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}isodate>0:devel/py-isodate@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}lxml>=5.0.0:devel/py-lxml@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}pycountry>0:textproc/py-pycountry@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}pycryptodome>=3.4.3:security/py-pycryptodome@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}pysocks>1.5.7:net/py-pysocks@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}requests>2.30.0:www/py-requests@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}trio>=0.22.0:net/py-trio@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}trio-websocket>=0.9.0:net/py-trio-websocket@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}urllib3>=2.0.0:net/py-urllib3@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}websocket-client>=1.2.1:www/py-websocket-client@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}freezegun>=1.5.0:devel/py-freezegun@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}pytest-trio>0:devel/py-pytest-trio@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}requests-mock>0:www/py-requests-mock@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517 pytest
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
NO_ARCH=	yes
OPTIONS_DEFINE=		BROTLI FFMPEG ZSTD
OPTIONS_DEFAULT=	FFMPEG
BROTLI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}brotli>0:archivers/py-brotli@${PY_FLAVOR}
FFMPEG_RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg
ZSTD_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zstandard>0:archivers/py-zstandard@${PY_FLAVOR}

.include <bsd.port.mk>
