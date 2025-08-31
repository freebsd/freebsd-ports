PORTNAME=	baycomp
DISTVERSION=	1.0.3
PORTREVISION=	2
CATEGORIES=	math python # statistics
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for Bayesian comparison of classifiers
WWW=		https://github.com/janezd/baycomp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=2.1.2:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.19.1:science/py-scipy@${PY_FLAVOR}
#RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pystan>=3.4.0:math/py-pystan@${PY_FLAVOR}

USES=		localbase:ldflags python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

POST_PLIST=	rm-tests-from-plist

post-install:
	@${RM} -r ${STAGEDIR}${PYTHON_SITELIBDIR}/tests

rm-tests-from-plist:
	@${REINPLACE_CMD} '/\/tests\//d' ${TMPPLIST}

.include <bsd.port.mk>
