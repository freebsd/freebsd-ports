# $FreeBSD$

PORTNAME=	defcon
PORTVERSION=	0.5.3
CATEGORIES=	x11-fonts python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lantw44@gmail.com
COMMENT=	Set of flexible objects for representing UFO data

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/License.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fonttools>=3.1.2:print/py-fonttools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ufoLib>=2.3.1:x11-fonts/py-ufoLib@${PY_FLAVOR}

USES=		python zip
USE_PYTHON=	autoplist distutils
USE_LOCALE=	en_US.UTF-8

NO_ARCH=	yes

.include <bsd.port.mk>
