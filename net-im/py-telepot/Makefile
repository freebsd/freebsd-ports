# $FreeBSD$

PORTNAME=	telepot
DISTVERSION=	12.0
CATEGORIES=	net-im python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python framework for Telegram Bot API

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}urllib3>0:net/py-urllib3@${FLAVOR}

USES=		python zip
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 3500
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}aiohttp>0:www/py-aiohttp@${FLAVOR}
.endif

.include <bsd.port.post.mk>
