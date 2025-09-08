PORTNAME=	django-unfold
PORTVERSION=	0.65.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	django_unfold-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Modern Django admin theme for seamless interface development
WWW=		https://unfoldadmin.com/ \
		https://github.com/unfoldadmin/django-unfold

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>=4.2:www/py-django42@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
