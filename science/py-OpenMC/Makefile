PORTNAME=	OpenMC
DISTVERSIONPREFIX=	v
DISTVERSION=	0.15.0
PORTREVISION=	2
CATEGORIES=	science
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Monte Carlo neutron and photon transport simulation code (Python)
WWW=		https://openmc.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}h5py>0:science/py-h5py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipython>0:devel/ipython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml5>0:devel/py-lxml5@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uncertainties>0:math/py-uncertainties@${PY_FLAVOR}
BUILD_DEPENDS=	openmc>0:science/openmc \
		${PY_DEPENDS}
RUN_DEPENDS=	openmc>0:science/openmc \
		${PY_DEPENDS}

USES=		python
USE_PYTHON=	distutils cython concurrent autoplist pytest # tests fail and abort in the middle, see https://github.com/openmc-dev/openmc/issues/2186

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME:tl}-dev
GH_PROJECT=	${PORTNAME:tl}

PLIST_FILES=	${PYTHON_SITELIBDIR}/openmc/lib/libopenmc.so

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
	# strip
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/openmc/data/*.so
	# link the library
	@${LN} -s ${LOCALBASE}/lib/libopenmc.so ${STAGEDIR}${PYTHON_SITELIBDIR}/openmc/lib/libopenmc.so

pre-test:
	# link the library
	@if ! [ -e ${WRKSRC}/openmc/lib/libopenmc.so ]; then ${LN} -s ${LOCALBASE}/lib/libopenmc.so ${WRKSRC}/openmc/lib/libopenmc.so; fi

# Some tests fail with the message: RuntimeError: No cross_sections.xml file was specified in materials.xml or in the OPENMC_CROSS_SECTIONS environment variable, see https://github.com/openmc-dev/openmc/issues/3053

.include <bsd.port.mk>
