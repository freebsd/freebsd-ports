# $FreeBSD$

PORTNAME=	luminol
PORTVERSION=	0.3.1
DISTVERSIONPREFIX=	v
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	Light weight python library for time series data analysis

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy \
	${PYTHON_PKGNAMEPREFIX}numpy>=1.6.2,1:math/py-numpy

USES=		python
USE_PYTHON=	autoplist distutils
USE_GITHUB=	yes
GH_ACCOUNT=	linkedin

.include <bsd.port.mk>
