# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	httpx
PORTVERSION=	0.22.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Next generation HTTP client

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

# idna is from rfc3986[idna2008]
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}certifi>=0:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}charset-normalizer>=0:textproc/py-charset-normalizer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpcore>=0.14.5<0.15.0:www/py-httpcore@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}idna>=0:dns/py-idna@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rfc3986>=1.3,1:www/py-rfc3986@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sniffio>=0:devel/py-sniffio@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	BROTLI CLI HTTP2 SOCKS
OPTIONS_DEFAULT=HTTP2
BROTLI_DESC=	Brotli support
CLI_DESC=	Command-line interface support
HTTP2_DESC=	HTTP/2 support

BROTLI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}brotli>=0:archivers/py-brotli@${PY_FLAVOR}
CLI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=8<9:devel/py-click@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pygments>=2<3:textproc/py-pygments@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}rich>=11:textproc/py-rich@${PY_FLAVOR}
HTTP2_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}h2>=3<5:www/py-h2@${PY_FLAVOR}
SOCKS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}socksio>=1<2:net/py-socksio@${PY_FLAVOR}

.include <bsd.port.mk>
