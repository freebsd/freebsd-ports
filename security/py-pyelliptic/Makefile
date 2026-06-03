PORTNAME=	pyelliptic
PORTVERSION=	2.0.1
PORTREVISION=	2
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python OpenSSL wrapper
WWW=		https://github.com/radfish/pyelliptic

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyopenssl>=0:security/py-pyopenssl@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	radfish
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
