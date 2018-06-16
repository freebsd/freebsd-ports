# $FreeBSD$

PORTNAME=	abipy
DISTVERSION=	0.5.0
CATEGORIES=	science python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for analyzing the results produced by ABINIT

LICENSE=	GPLv2

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}apscheduler>=2.1.0:devel/py-apscheduler@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}html2text>0:textproc/py-html2text@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netCDF4>0:science/py-netCDF4@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prettytable>0:devel/py-prettytable@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydispatcher>=2.0.5:devel/py-pydispatcher@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymatgen>=2018.6.11:science/py-pymatgen@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}seaborn>0:math/py-seaborn@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spglib>0:science/py-spglib@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tabulate>0:devel/py-tabulate@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>0:misc/py-tqdm@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.11:devel/py-yaml@${FLAVOR}

USES=		python shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	abinit
SHEBANG_GLOB=	*.py
USE_PYTHON=	distutils concurrent autoplist

.include <bsd.port.mk>
