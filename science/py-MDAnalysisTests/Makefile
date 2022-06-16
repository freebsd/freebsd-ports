PORTNAME=	MDAnalysisTests
DISTVERSION=	2.2.0
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Test code and the trajectory data for test cases of MDAnalysis

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}MDAnalysis>0:science/py-MDAnalysis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fasteners>0:devel/py-fasteners@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hypothesis>0:devel/py-hypothesis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=4.0.2:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=2.0.0:devel/py-mock@${PY_FLAVOR}

USES=		pytest python:3.8+
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
