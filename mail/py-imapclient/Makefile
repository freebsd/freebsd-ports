PORTNAME=	imapclient
DISTVERSION=	3.0.1
CATEGORIES=	mail python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	IMAPClient-${PORTVERSION}

MAINTAINER=	meka@tilda.center
COMMENT=	Easy to use, Pythonic and complete IMAP client library
WWW=		https://github.com/mjs/imapclient

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR}

USES=		python zip
USE_PYTHON=	autoplist concurrent distutils pytest

NO_ARCH=	yes

.include <bsd.port.mk>
