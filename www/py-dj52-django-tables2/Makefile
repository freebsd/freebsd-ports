PORTNAME=	django-tables2
DISTVERSION=	2.8.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj52-
DISTNAME=	django_tables2-${DISTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Table/data-grid framework for Django
WWW=		https://github.com/jieter/django-tables2

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django52>=4.2:www/py-django52@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*${PORTNAME}

NO_ARCH=		yes

OPTIONS_DEFINE=		TABLIB

TABLIB_DESC=		Enable support for exporting table datasets
TABLIB_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tablib>=0:textproc/py-tablib@${PY_FLAVOR}

.include <bsd.port.mk>
