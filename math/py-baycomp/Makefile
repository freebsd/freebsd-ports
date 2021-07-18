PORTNAME=	baycomp
DISTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	math python # statistics
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for Bayesian comparison of classifiers

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=2.1.2:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.19.1:science/py-scipy@${PY_FLAVOR}

USES=		localbase:ldflags python:3.7+
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

POST_PLIST=	rm-tests-from-plist

post-install:
	@${RM} -r ${STAGEDIR}${PYTHON_SITELIBDIR}/tests

rm-tests-from-plist:
	@${REINPLACE_CMD} '/\/tests\//d' ${TMPPLIST}

.include <bsd.port.mk>
