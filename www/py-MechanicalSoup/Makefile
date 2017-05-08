# Created by: Thomas Zander <riggs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MechanicalSoup
PORTVERSION=	0.7.0
DISTVERSIONPREFIX=	v
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python library for automating interaction with websites

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4:www/py-beautifulsoup \
		${PYTHON_PKGNAMEPREFIX}requests>=2.11:www/py-requests \
		${PYTHON_PKGNAMEPREFIX}six>=1.10:devel/py-six

USE_GITHUB=	yes
GH_ACCOUNT=	hickford

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
