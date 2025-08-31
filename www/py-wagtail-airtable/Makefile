PORTNAME=	wagtail-airtable
PORTVERSION=	1.0.0
PORTREVISION=	2
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
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>=4.2:www/py-django42@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}djangorestframework>=3.11.0,1:www/py-djangorestframework@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyairtable2>=2.3<3:devel/py-pyairtable2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wagtail>=5.2:www/py-wagtail@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
