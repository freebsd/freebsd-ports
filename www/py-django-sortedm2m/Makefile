PORTNAME=	django-sortedm2m
PORTVERSION=	4.0.0
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@caomhin.org
COMMENT=	Replacement for Django's many to many field #'
WWW=		https://github.com/jazzband/django-sortedm2m

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>=4.2:www/py-django42@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	jazzband
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>
