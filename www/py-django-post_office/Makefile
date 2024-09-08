PORTNAME=	django-post_office
DISTVERSIONPREFIX=	v
DISTVERSION=	3.9
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ultima@FreeBSD.org
COMMENT=	Django app to monitor and send mail asynchronously
WWW=		https://github.com/ui/django-post_office

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>=3.2:www/py-django42@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bleach>=0:www/py-bleach@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=0:devel/py-pytz@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils
USE_LOCALE=	en_US.UTF-8

USE_GITHUB=	yes
GH_ACCOUNT=	ui

NO_ARCH=	yes

.include <bsd.port.mk>
