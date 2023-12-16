PORTNAME=	fbmq
PORTVERSION=	2.5.0
CATEGORIES=	net-im devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Python library for using the Facebook Messenger API
WWW=		https://github.com/conbus/fbmq

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flask>0:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
