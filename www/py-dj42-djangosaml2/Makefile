PORTNAME=	djangosaml2
PORTVERSION=	1.11.1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj42-

MAINTAINER=	ultima@FreeBSD.org
COMMENT=	Pysaml2 integration for Django
WWW=		https://github.com/IdentityPython/djangosaml2

LICENSE=	APACHE20

DEPRECATED=	Serves as a transition only for www/seahub and requires Django 4.2, which has been end-of-life since April
EXPIRATION_DATE=2026-08-31

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>=4.2:www/py-django42@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysaml2>=6.5.1:security/py-pysaml2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}defusedxml>=0.4.1:devel/py-defusedxml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*${PORTNAME}

NO_ARCH=	yes

.include <bsd.port.mk>
