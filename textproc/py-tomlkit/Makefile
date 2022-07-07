# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	tomlkit
PORTVERSION=	0.11.1
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Style-preserving TOML library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>=0:devel/py-yaml@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils pytest

NO_ARCH=	yes

post-patch:
	@${MV} ${WRKSRC}/tests ${WRKSRC}/tomlkit

.include <bsd.port.mk>
