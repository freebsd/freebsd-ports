PORTNAME=	aiosmtpd
PORTVERSION=	1.4.2
CATEGORIES=	mail python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Asyncio based SMTP server

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}atpublic>=0:devel/py-atpublic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}attrs>=0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>
