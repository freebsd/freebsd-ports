# Created by: Carlo Strub
# $FreeBSD$

PORTNAME=	stem
PORTVERSION=	1.5.4
PORTREVISION=	1
CATEGORIES=	security net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Python controller library for Tor

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycrypto>0:security/py-pycrypto
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock \
		${PYTHON_PKGNAMEPREFIX}pyflakes>0:devel/py-pyflakes \
		${PYTHON_PKGNAMEPREFIX}pycodestyle>0:devel/py-pycodestyle

USES=		python:2.6+
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} run_tests.py -a

.include <bsd.port.mk>
