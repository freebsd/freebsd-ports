# Created by: Rainer Hurling <rhurlin@gwdg.de>

PORTNAME=	matplotlib-scalebar
PORTVERSION=	0.7.2
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rhurlin@FreeBSD.org
COMMENT=	Artist for matplotlib to display a scale bar

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>=0:math/py-matplotlib@${PY_FLAVOR}

USES=		python:3.7+
USE_LOCALE=	en_US.UTF-8
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
