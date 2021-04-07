PORTNAME=	merkletools
DISTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tools for working with Merkle trees

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pysha3>0:security/py-pysha3@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist

NO_ARCH=	yesA

POST_PLIST=	rm-tests-from-plist

post-install:
	@${RM} -r ${STAGEDIR}${PYTHON_SITELIBDIR}/tests

rm-tests-from-plist:
	@${REINPLACE_CMD} '/\/tests\//d' ${TMPPLIST}

.include <bsd.port.mk>
