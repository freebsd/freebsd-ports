PORTNAME=	djangosaml2
PORTVERSION=	1.8.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ultima@FreeBSD.org
COMMENT=	Pysaml2 integration for Django
WWW=		https://github.com/IdentityPython/djangosaml2

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django32>=3.2:www/py-django32@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysaml2>=6.5.1:security/py-pysaml2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}defusedxml>=0.4.1:devel/py-defusedxml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
