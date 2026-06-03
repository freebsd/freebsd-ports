PORTNAME=	openbabel
DISTVERSION=	3.2.0
CATEGORIES=	science # chemistry
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Chemical toolbox designed to speak the many languages of chemical data
WWW=		https://openbabel.org/wiki/Main_Page

LICENSE=	GPLv2+

BUILD_DEPENDS=	swig:devel/swig \
		rapidjson>0:devel/rapidjson \
		${PYTHON_PKGNAMEPREFIX}cmeel-eigen>0:devel/py-cmeel-eigen@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-build-core>=0.11:devel/py-scikit-build-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}swig>0:devel/py-swig@${PY_FLAVOR}
LIB_DEPENDS=	libcoordgen.so:science/coordgenlibs \
		libmaeparser.so:science/maeparser \
		libopenbabel.so:science/openbabel \
		libxml2.so:textproc/libxml2

USES=		python
USE_PYTHON=	pep517 autoplist pytest

BINARY_ALIAS=	python=${PYTHON_CMD}

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/test

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/openbabel/_openbabel.so

.include <bsd.port.mk>
