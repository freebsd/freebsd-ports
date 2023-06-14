PORTNAME=	wagtail-factories
PORTVERSION=	4.1.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	wagtail_factories-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Factory boy classes for wagtail
WWW=		https://github.com/wagtail/wagtail-factories

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}factory-boy>=3.2:devel/py-factory-boy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wagtail>=4.1:www/py-wagtail@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
