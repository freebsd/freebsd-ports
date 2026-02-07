PORTNAME=	openssh-wrapper
PORTVERSION=	0.4
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	einar@isnic.is
COMMENT=	OpenSSH python wrapper
WWW=		https://github.com/NetAngels/openssh-wrapper

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		cpe python
USE_PYTHON=	autoplist cryptography pep517

NO_ARCH=	yes

.include <bsd.port.mk>
