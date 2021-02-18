# Created by: Ulf Lilleengen
# $FreeBSD$

PORTNAME=	paramiko
PORTVERSION=	2.7.2
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Python SSH2 protocol library

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bcrypt>=3.1.3:security/py-bcrypt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>=2.5:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyasn1>=0.1.7:devel/py-pyasn1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pynacl>=1.0.1:security/py-pynacl@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}paramiko1
NO_ARCH=		yes

do-test:
	@(cd ${WRKSRC} && ${PYTHON_CMD} -m unittest discover .)

.include <bsd.port.mk>
