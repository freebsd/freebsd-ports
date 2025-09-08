PORTNAME=	urllib3-future
PORTVERSION=	2.13.906
CATEGORIES=	net python
MASTER_SITES=	PYPI \
		https://github.com/jawah/urllib3.future/releases/download/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	urllib3_future-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Powerful HTTP 1.1, 2, and 3 client with both sync and async interfaces
WWW=		https://urllib3future.readthedocs.io/en/latest/ \
		https://github.com/jawah/urllib3.future

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=1.6.0<2:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}h11>=0.11.0<1.0.0:net/py-h11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jh2>=5.0.3<6.0.0:www/py-jh2@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	BROTLI SOCKS WS ZSTD
WS_DESC=	WebSockets support

BROTLI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}brotli>=1.0.9:archivers/py-brotli@${PY_FLAVOR}
SOCKS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-socks>=2.0<2.6.1_99:net/py-python-socks@${PY_FLAVOR}
WS_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}wsproto>=1.2<2:net/py-wsproto@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MZSTD} && ${PYTHON_REL} < 31400
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}zstandard>=0.18.0:archivers/py-zstandard@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
