PORTNAME=	wagtail-localize
PORTVERSION=	1.12
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	PYPI
DISTNAME=	wagtail_localize-${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Translation plugin for Wagtail CMS
WWW=		https://wagtail-localize.org/latest/ \
		https://github.com/wagtail/wagtail-localize

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>=4.2<6.0:www/py-django42@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flit-core>=3.11<4:devel/py-flit-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}polib>=1.1<2.0:devel/py-polib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wagtail>=5.2:www/py-wagtail@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>=4.2<6.0:www/py-django42@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}polib>=1.1<2.0:devel/py-polib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wagtail>=5.2:www/py-wagtail@${PY_FLAVOR}

USES=		python:3.9+
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
