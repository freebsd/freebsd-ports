PORTNAME=	python-telegram-bot
PORTVERSION=	21.6
PORTREVISION=	1
CATEGORIES=	net-im devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=    ${PORTNAME:S/-/_/g}-${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Not just a Python wrapper around the Telegram Bot API
WWW=		https://python-telegram-bot.org/

LICENSE=	LGPL3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}APScheduler>0:devel/py-apscheduler@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>=0.27.0:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>0:net/py-urllib3@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python
USE_PYTHON=	pep517 autoplist

.include <bsd.port.mk>
