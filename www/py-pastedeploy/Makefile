PORTNAME=	pastedeploy
PORTVERSION=	3.1.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PasteDeploy-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Load, configure, and compose WSGI applications and servers
WWW=		https://pylonsproject.org/ \
		https://github.com/Pylons/pastedeploy

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=41:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
