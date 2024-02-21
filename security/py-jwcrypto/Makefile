PORTNAME=	jwcrypto
PORTVERSION=	1.5.4
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Implementation of JOSE Web standards
WWW=		https://jwcrypto.readthedocs.io/en/latest/ \
		https://github.com/latchset/jwcrypto

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.5.0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cryptography distutils

NO_ARCH=	yes

.include <bsd.port.mk>
