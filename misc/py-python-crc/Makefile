PORTNAME=	crc
DISTVERSION=	7.1.0
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}python- # because it builds crc*.whl

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Pure Python CRC library
WWW=		https://nicoretti.github.io/crc/ \
		https://github.com/Nicoretti/crc

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>0:devel/py-poetry-core@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 concurrent autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
