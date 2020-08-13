# Created by: Yuri Victorovich
# $FreeBSD$

PORTNAME=	pyaxo
DISTVERSION=	0.8.2
PORTREVISION=	2
CATEGORIES=	security net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python implementation of the Axolotl ratchet protocol

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}passlib>=1.6.1:security/py-passlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pynacl>=1.0.1:security/py-pynacl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e "/'pytest-runner',/d" ${WRKSRC}/setup.py

do-test:
	@(cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -v -rs)

.include <bsd.port.mk>
