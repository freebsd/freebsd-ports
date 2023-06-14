PORTNAME=	deap
DISTVERSION=	1.3.3
PORTREVISION=	1
CATEGORIES=	math biology science devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Distributed Evolutionary Algorithms in Python
WWW=		https://github.com/DEAP/deap

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY}

USES=		python
USE_PYTHON=	distutils autoplist pytest # tests fail, see https://github.com/DEAP/deap/issues/668

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/deap/tools/_hypervolume/hv${PYTHON_EXT_SUFFIX}.so

.include <bsd.port.mk>
