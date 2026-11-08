PORTNAME=	pygeodesy
PORTVERSION=	26.9.9
CATEGORIES=	science python
MASTER_SITES=	PYPI \
		https://github.com/mrJean1/PyGeodesy/raw/master/dist/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Pure Python geodesy tools
WWW=		https://mrjean1.github.io/PyGeodesy/ \
		https://github.com/mrJean1/PyGeodesy

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
