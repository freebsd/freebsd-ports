PORTNAME=	robot-detection
DISTVERSION=	0.4
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	einar@isnic.is
COMMENT=	Detect if a HTTP User-Agent header is likely to be a bot
WWW=		https://github.com/amandasaurus/robot-detection

LICENSE=	GPLv3+

USES=		python
USE_PYTHON=	autoplist distutils

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}

.include <bsd.port.mk>
