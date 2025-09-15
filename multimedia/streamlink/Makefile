PORTNAME=	streamlink
DISTVERSION=	6.5.1
PORTREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	takefu@airport.fm
COMMENT=	Command-line utility that pipes video streams
WWW=		https://streamlink.github.io/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS}\
		${PYTHON_PKGNAMEPREFIX}versioningit>=2.0.0:devel/py-versioningit@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}certifi>0:security/py-certifi@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}country>0:devel/py-country@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}isodate>0:devel/py-isodate@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}lxml>=4.6.4:devel/py-lxml@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}pycryptodome>=3.4.3:security/py-pycryptodome@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}pysocks>1.5.7:net/py-pysocks@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}requests>2.26.0:www/py-requests@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}trio>=0.22.0:net/py-trio@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}trio-websocket>=0.9.0:net/py-trio-websocket@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.0.0:devel/py-typing-extensions@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}urllib3>=1.26.0:net/py-urllib3@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}websocket-client>=1.2.1:www/py-websocket-client@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}backports>0:devel/py-backports@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}freezegun>0:devel/py-freezegun@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>0:devel/py-pytest-asyncio@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}pytest-trio>0:devel/py-pytest-trio@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}requests-mock>0:www/py-requests-mock@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils pytest
NO_ARCH=	yes
OPTIONS_DEFINE=		FFMPEG
OPTIONS_DEFAULT=	FFMPEG
FFMPEG_RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg

.include <bsd.port.mk>
