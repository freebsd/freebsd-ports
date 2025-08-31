PORTNAME=	MDAnalysisTests
DISTVERSION=	2.7.0
PORTREVISION=	2
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Test code and the trajectory data for test cases of MDAnalysis
WWW=		https://www.mdanalysis.org

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}MDAnalysis>0:science/py-MDAnalysis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hypothesis>0:devel/py-hypothesis@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest
NO_ARCH=	yes

.include <bsd.port.mk>
