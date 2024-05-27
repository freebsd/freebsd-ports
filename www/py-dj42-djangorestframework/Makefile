PORTNAME=	djangorestframework
PORTVERSION=	3.14.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj42-

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Django REST framework
WWW=		https://www.django-rest-framework.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

DEPRECATED=	Obsolete, please use www/py-djangorestframework instead
EXPIRATION_DATE=2024-06-15

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>=3.0:www/py-django42@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=0:devel/py-pytz@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*${PORTNAME}
NO_ARCH=		yes

.include <bsd.port.mk>
