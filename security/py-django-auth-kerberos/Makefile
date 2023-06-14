PORTNAME=	django-auth-kerberos
PORTVERSION=	1.2.5
PORTREVISION=	2
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Kerberos authentication backend for Django
WWW=		https://github.com/02strich/django-auth-kerberos

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}kerberos>1.1.10:security/py-kerberos@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>=0:devel/py-coverage@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
