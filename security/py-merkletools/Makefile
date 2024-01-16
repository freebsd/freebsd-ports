PORTNAME=	merkletools
DISTVERSION=	1.0.3
PORTREVISION=	2
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tools for working with Merkle trees
WWW=		https://github.com/Tierion/pymerkletools

LICENSE=	MIT

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yesA

POST_PLIST=	rm-tests-from-plist

post-patch:
	@${RM} ${WRKSRC}/requirements.txt ${WRKSRC}/merkletools.egg-info/requires.txt
	@${REINPLACE_CMD} -e '/pysha3/d' ${WRKSRC}/setup.py

post-install:
	@${RM} -r ${STAGEDIR}${PYTHON_SITELIBDIR}/tests

rm-tests-from-plist:
	@${REINPLACE_CMD} '/\/tests\//d' ${TMPPLIST}

.include <bsd.port.mk>
