# Created by: Richard Gallamore <ultima@FreeBSD.org>

PORTNAME=	parso
DISTVERSION=	0.8.3
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ultima@FreeBSD.org
COMMENT=	Python Parser

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest<6.0.0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docopt>=0:devel/py-docopt@${PY_FLAVOR}

USES=		cpe python:3.6+
CPE_VENDOR=	${PORTNAME}_project
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

do-test:
		cd ${WRKSRC} && ${PYTHON_CMD} -m pytest test

.include <bsd.port.mk>
