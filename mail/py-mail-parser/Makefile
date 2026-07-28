PORTNAME=	mail-parser
PORTVERSION=	4.4.0
CATEGORIES=	mail python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Wrapper for email standard library
WWW=		https://github.com/SpamScope/mail-parser

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	msgconvert:mail/p5-Email-Outlook-Message

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
