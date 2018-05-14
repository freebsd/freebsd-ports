# $FreeBSD$

PORTNAME=	MDAnalysisTests
DISTVERSION=	0.18.0
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Test code and the trajectory data for test cases of MDAnalysis

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}MDAnalysis>0:science/py-MDAnalysis@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=3.1.2:devel/py-pytest@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hypothesis>0:devel/py-hypothesis@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=4.0.2:sysutils/py-psutil@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=2.0.0:devel/py-mock@${FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
