PORTNAME=	zkg
DISTVERSIONPREFIX=	v
DISTVERSION=	2.10.0
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mshirk@daemon-security.com
COMMENT=	Zeek NSM package manager

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gitpython>=2.1.8:devel/py-gitpython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}btest>=0.62:devel/py-btest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}configparser>=0:devel/py-configparser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}semantic-version>=0:devel/py-semantic-version@${PY_FLAVOR} \
		git:devel/git

USES=		python:3.6+
USE_GITHUB=	yes
GH_ACCOUNT=	zeek
GH_PROJECT=	package-manager
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
