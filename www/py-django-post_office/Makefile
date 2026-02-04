PORTNAME=	django-post_office
DISTVERSIONPREFIX=	v
DISTVERSION=	3.11
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ultima@FreeBSD.org
COMMENT=	Django app to monitor and send mail asynchronously
WWW=		https://github.com/ui/django-post_office

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>=4.2:www/py-django42@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nh3>0:www/py-nh3@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

USE_GITHUB=	yes
GH_ACCOUNT=	ui

NO_ARCH=	yes

.include <bsd.port.mk>
