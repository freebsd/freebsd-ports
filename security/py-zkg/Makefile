# $FreeBSD$

PORTNAME=	zkg
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.2
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mshirk@daemon-security.com
COMMENT=	Zeek NSM package manager

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}GitPython>=2.1.8:devel/py-gitpython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}btest>=0:devel/py-btest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}configparser>=0:devel/py-configparser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}semantic_version>=0:devel/py-semantic_version@${PY_FLAVOR} \
		git:devel/git

USES=		python
USE_PYTHON=	distutils autoplist concurrent

USE_GITHUB=	yes
GH_ACCOUNT=	zeek
GH_PROJECT=	package-manager

NO_ARCH=	yes

.include <bsd.port.mk>
