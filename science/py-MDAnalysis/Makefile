# $FreeBSD$

PORTNAME=	MDAnalysis
DISTVERSION=	0.19.2
PORTREVISION=	1
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python library to analyze molecular dynamics trajectories

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}biopython>=1.71:biology/py-biopython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}duecredit>0:textproc/py-duecredit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}GridDataFormats>=0.4.0:math/py-GridDataFormats@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gsd>=1.4.0:science/py-gsd@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}joblib>0:devel/py-joblib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=1.5.1:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mmtf-python>=1.0.0:science/py-mmtf-python@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>=1.0:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.0.0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.4.0:devel/py-six@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
