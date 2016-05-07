# Created by: Thomas Zander <riggs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MechanicalSoup
PORTVERSION=	0.4.0
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python library for automating interaction with websites

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.7.0:www/py-requests \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>4:www/py-beautifulsoup \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six

USE_GITHUB=	yes
GH_ACCOUNT=	hickford
GH_TAGNAME=	cb0c94d

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
