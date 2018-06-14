# $FreeBSD$

PORTNAME=	orange3-timeseries
DISTVERSION=	0.3.3
CATEGORIES=	misc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Orange add-on for analyzing, visualizing, manipulating time series

LICENSE=	CC-BY-3.0
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	orange3>0:misc/orange3 \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas-datareader>0:math/py-pandas-datareader@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.17:science/py-scipy@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}statsmodels>=0.6.1>0:math/py-statsmodels@${FLAVOR}

USES=		python:3.4+
USE_GITHUB=	yes
GH_ACCOUNT=	biolab
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
