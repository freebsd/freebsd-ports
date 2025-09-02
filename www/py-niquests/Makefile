PORTNAME=	niquests
PORTVERSION=	3.15.0
CATEGORIES=	www python
MASTER_SITES=	PYPI \
		https://github.com/jawah/niquests/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple, yet elegant, HTTP library
WWW=		https://niquests.readthedocs.io/en/stable/ \
		https://github.com/jawah/niquests

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=1.6.0<2:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}charset-normalizer>=2<4:textproc/py-charset-normalizer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3-future>=2.13.903<3:net/py-urllib3-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wassima>=1.0.1<3:security/py-wassima@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	BROTLI ZSTD

BROTLI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}brotli>=1.0.9:archivers/py-brotli@${PY_FLAVOR}
ZSTD_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zstandard>=0.18.0:archivers/py-zstandard@${PY_FLAVOR}

.include <bsd.port.mk>
