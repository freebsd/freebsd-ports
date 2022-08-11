PORTNAME=	ed25519ll
PORTVERSION=	0.6
PORTREVISION=	2
CATEGORIES=	security
#MASTER_SITES=	CHEESESHOP
# bitbucket master contains py3 fixes made after last tagged release
MASTER_SITES=	https://bitbucket.org/dholth/${PORTNAME}/get/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	37719c56b7b6

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Low-level ctypes wrapper for Ed25519 digital signatures

LICENSE=	MIT

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>=0:devel/py-nose@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils flavors

WRKSRC=		${WRKDIR}/dholth-${PORTNAME}-${DISTNAME}

do-test:
	cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.mk>
