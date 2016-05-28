# $FreeBSD$

PORTNAME=	pyotp
PORTVERSION=	2.1.1
DISTVERSIONPREFIX=	v
CATEGORIES=	security
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	vlad-fbsd@acheronmedia.com
COMMENT=	Python One Time Password Library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes

USES=		python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

do-test:
	@(cd ${WRKSRC}/${PORTNAME} && ${PYTHON_CMD} test.py)

.include <bsd.port.mk>
