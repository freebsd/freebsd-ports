PORTNAME=	scikit-fusion
DISTVERSION=	0.2.1
PORTREVISION=	2
CATEGORIES=	misc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Data fusion based on recent collective latent factor models

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}joblib>=0.8.4:devel/py-joblib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.12.0:science/py-scipy@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>
