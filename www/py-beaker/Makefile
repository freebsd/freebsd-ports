PORTNAME=	beaker
PORTVERSION=	1.13.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Beaker-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Session and Caching library with WSGI Middleware
WWW=		https://beaker.readthedocs.io/en/latest/ \
		https://github.com/bbangert/beaker

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		cpe python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

CPE_VENDOR=	beakerbrowser

.include <bsd.port.mk>
