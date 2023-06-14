PORTNAME=	pyberny
DISTVERSION=	0.6.3
PORTREVISION=	1
CATEGORIES=	science # chemistry
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Optimizer of molecular geometries with respect to the total energy
WWW=		https://github.com/jhrmnn/pyberny

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYNUMPY}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils concurrent autoplist

NO_ARCH=	yes

do-test: install # no tests run, see https://github.com/jhrmnn/pyberny/issues/36
	@cd ${WRKSRC} && pytest -rs --pyargs berny

.include <bsd.port.mk>
