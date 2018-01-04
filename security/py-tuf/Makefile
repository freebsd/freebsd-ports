# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tuf
PORTVERSION=	0.10.0
CATEGORIES=	security devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Framework for securing software update systems

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}iso8601>0:devel/py-iso8601@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cryptography>0:security/py-cryptography@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycrypto>0:security/py-pycrypto@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pynacl>0:security/py-pynacl@${FLAVOR}

# Actually 2.6-3.5
USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC}/tests && ${PYTHON_CMD} -m pytest -rsv

.include <bsd.port.mk>
