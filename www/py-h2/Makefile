PORTNAME=	h2
PORTVERSION=	4.1.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	shaun@FreeBSD.org
COMMENT=	HTTP/2 State-Machine based protocol implementation
WWW=		https://hyper.rtfd.org/

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hyperframe>=6.0:www/py-hyperframe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hpack>=4.0<5:www/py-hpack@${PY_FLAVOR}

USES?=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
