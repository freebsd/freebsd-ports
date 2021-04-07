PORTNAME=	luminol
PORTVERSION=	0.3.1
PORTREVISION=	3
DISTVERSIONPREFIX=	v
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Light weight python library for time series data analysis

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}numpy>=1.6.2,1:math/py-numpy@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils
USE_GITHUB=	yes
GH_ACCOUNT=	linkedin

.include <bsd.port.mk>
