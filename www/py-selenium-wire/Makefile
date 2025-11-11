PORTNAME=	selenium-wire
PORTVERSION=	5.1.0
PORTREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Access to the underlying Selenium requests
WWW=		https://github.com/wkeeling/selenium-wire

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}blinker>=1.4:devel/py-blinker@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}brotli>=1.0.9:archivers/py-brotli@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certifi>=2019.9.1:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h2>=4.0:www/py-h2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hyperframe>=6.0:www/py-hyperframe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}kaitaistruct>=0.7:devel/py-kaitaistruct@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyasn1>=0.3.1:devel/py-pyasn1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyopenssl>=19.1.0:security/py-pyopenssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyparsing>=2.4.2:devel/py-pyparsing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysocks>=1.7.1:net/py-pysocks@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}selenium>=3.4.0:www/py-selenium@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wsproto>0.14:net/py-wsproto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zstandard>=0.14.1:archivers/py-zstandard@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
