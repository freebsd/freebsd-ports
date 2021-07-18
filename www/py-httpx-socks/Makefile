PORTNAME=	httpx-socks
PORTVERSION=	0.4.1
DISTVERSIONPREFIX=	v
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Proxy (HTTP, SOCKS) transports for httpx

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}httpcore>=0.13.0<0.14:www/py-httpcore@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>0:www/py-httpx@${PY_FLAVOR}  \
		${PYTHON_PKGNAMEPREFIX}async_timeout>0:devel/py-async_timeout@${PY_FLAVOR}  \
		${PYTHON_PKGNAMEPREFIX}trio>0:net/py-trio@${PY_FLAVOR}  \
		${PYTHON_PKGNAMEPREFIX}curio>0:devel/py-curio@${PY_FLAVOR}  \
		${PYTHON_PKGNAMEPREFIX}python-socks>0:net/py-python-socks@${PY_FLAVOR}  \
		${PYTHON_PKGNAMEPREFIX}sniffio>=0:devel/py-sniffio@${PY_FLAVOR}

USES=		python:3.7+
USE_GITHUB=	yes
GH_ACCOUNT=	romis2012
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
