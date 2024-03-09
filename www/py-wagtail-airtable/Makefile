PORTNAME=	wagtail-airtable
PORTVERSION=	0.7.0
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	wagtail_airtable-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Sync data between Wagtail and Airtable
WWW=		https://github.com/wagtail-nest/wagtail-airtable

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.2<4:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}airtable-python-wrapper>=0.13.0:devel/py-airtable-python-wrapper@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django42>=3.2:www/py-django42@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj42-djangorestframework>=3.11.0:www/py-dj42-djangorestframework@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wagtail>=5.2:www/py-wagtail@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
