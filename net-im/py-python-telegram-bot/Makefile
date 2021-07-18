# Created by: Dmitry Sivachenko <demon@FreeBSD.org>

PORTNAME=	python-telegram-bot
PORTVERSION=	13.1
PORTREVISION=	1
CATEGORIES=	net-im devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Not just a Python wrapper around the Telegram Bot API

LICENSE=	LGPL3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}decorator>0:devel/py-decorator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>0:net/py-urllib3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}apscheduler>0:devel/py-apscheduler@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python:3.6+
USE_PYTHON=	autoplist distutils
PYDISTUTILS_BUILDARGS=	--with-upstream-urllib3

.include <bsd.port.mk>
