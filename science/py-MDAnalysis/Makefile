PORTNAME=	MDAnalysis
DISTVERSION=	2.7.0
PORTREVISION=	2
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python library to analyze molecular dynamics trajectories
WWW=		https://www.mdanalysis.org

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}packaging>=2.0:devel/py-packaging@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY} \
		clustalw2:biology/clustalw \
		rdkit>0:science/rdkit \
		${PYTHON_PKGNAMEPREFIX}biopython>=1.71:biology/py-biopython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}GridDataFormats>=0.4.0:math/py-GridDataFormats@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fasteners>0:devel/py-fasteners@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gsd>=1.9.3:science/py-gsd@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}joblib>0:devel/py-joblib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=1.5.1:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mmtf-python>=1.0.0:science/py-mmtf-python@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>=2.0:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.5.0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}seaborn>0:math/py-seaborn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.4.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.43.0:misc/py-tqdm@${PY_FLAVOR}

USES=		compiler:c++11-lang python
USE_PYTHON=	distutils cython autoplist

.if !defined(WITH_DEBUG)
LDFLAGS+=	-s
.endif

.include <bsd.port.mk>
