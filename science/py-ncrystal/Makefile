PORTNAME=	ncrystal
DISTVERSIONPREFIX=	v
DISTVERSION=	4.2.6
CATEGORIES=	science # physics
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for thermal neutron transport in crystals and other materials
WWW=		https://mctools.github.io/ncrystal/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scikit-build-core>0:devel/py-scikit-build-core@${PY_FLAVOR} \
		cmake:devel/cmake-core
RUN_DEPENDS=	${PYNUMPY}

USES=		python
USE_PYTHON=	pep517 concurrent autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	mctools

TEST_ENV=	${MAKE_ENV} \
		PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		PATH=${STAGEDIR}${PREFIX}/bin:${PATH}
#TEST_WRKSRC=	${WRKSRC}/ncrystal_python

post-install:
	# strip binary
	#@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/NCrystal/ncrystal_pyinst_data/lib/libNCrystal.so

do-test:
	@cd ${TEST_WRKSRC} && \
		${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m NCrystal.test all

.include <bsd.port.mk>
