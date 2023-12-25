PORTNAME=	httpx
PORTVERSION=	0.26.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Next generation HTTP client
WWW=		https://www.python-httpx.org/ \
		https://github.com/encode/httpx

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-fancy-pypi-readme>=0:devel/py-hatch-fancy-pypi-readme@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}anyio>=0:devel/py-anyio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certifi>=0:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpcore>=1<2:www/py-httpcore@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}idna>=0:dns/py-idna@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sniffio>=0:devel/py-sniffio@${PY_FLAVOR}

USES=		cpe python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

CPE_VENDOR=	encode

OPTIONS_DEFINE=	BROTLI CLI HTTP2 SOCKS
OPTIONS_DEFAULT=HTTP2
BROTLI_DESC=	Brotli support
CLI_DESC=	Command-line interface support
HTTP2_DESC=	HTTP/2 support

BROTLI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}brotli>=0:archivers/py-brotli@${PY_FLAVOR}
CLI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=8<9:devel/py-click@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pygments>=2<3:textproc/py-pygments@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}rich>=10<14:textproc/py-rich@${PY_FLAVOR}
HTTP2_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}h2>=3<5:www/py-h2@${PY_FLAVOR}
SOCKS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}socksio>=1<2:net/py-socksio@${PY_FLAVOR}

.include <bsd.port.mk>
