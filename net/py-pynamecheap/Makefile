PORTNAME=	pynamecheap
PORTVERSION=	0.0.3
CATEGORIES=	net python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyNamecheap-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Namecheap API client in Python
WWW=		https://github.com/Bemmu/PyNamecheap

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
