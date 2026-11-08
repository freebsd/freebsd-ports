PORTNAME=	wagtail-factories
PORTVERSION=	4.5.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	wagtail_factories-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Factory boy classes for wagtail
WWW=		https://wagtail-factories.readthedocs.io/en/latest/ \
		https://github.com/wagtail/wagtail-factories

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}factory-boy>=3.2<4:devel/py-factory-boy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wagtail>=7.0:www/py-wagtail@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
