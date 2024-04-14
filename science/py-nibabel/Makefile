PORTNAME=	nibabel
DISTVERSION=	5.2.1
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Read/write some common neuroimaging file formats
WWW=		https://nipy.org/nibabel/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-vcs>0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}packaging>=17:devel/py-packaging@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-doctestplus>0:devel/py-pytest-doctestplus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-httpserver>0:devel/py-pytest-httpserver@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>0:devel/py-pytest-xdist@${PY_FLAVOR}
TEST_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pydicom>0:science/py-pydicom@${PY_FLAVOR}

USES=		python:3.9+
USE_PYTHON=	pep517 concurrent autoplist pytest # 270 tests fail, see https://github.com/nipy/nibabel/issues/1317

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PATH=${STAGEDIR}${PREFIX}/bin

post-install:
	@${REINPLACE_CMD} -i '' -e 's|#!python|#!${PYTHON_CMD}|' \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/nibabel/cmdline/diff.py  \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/nibabel/cmdline/ls.py 

.include <bsd.port.mk>
