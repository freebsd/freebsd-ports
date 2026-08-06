PORTNAME=	ufal.udpipe
PORTVERSION=	1.4.0.1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/./_/}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python bindings to UDPipe library for parsing universal treebanks
WWW=		https://ufal.mff.cuni.cz/udpipe

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=		powerpc powerpc64 powerpcspe
NOT_FOR_ARCHS_REASON=	Only little endian systems are supported!

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		compiler:c++11-lang python
USE_PYTHON=	pep517 autoplist pytest

WRKSRC=		${WRKDIR}/ufal_udpipe-${PORTVERSION}

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests
TEST_ARGS=	-p no:black -p no:mypy

# tests as of 1.4.0.1: 2 passed in 4.94s

.include <bsd.port.mk>
