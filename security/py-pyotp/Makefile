# $FreeBSD$

PORTNAME=	pyotp
PORTVERSION=	2.0.1
CATEGORIES=	security
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	vlad-fbsd@acheronmedia.com
COMMENT=	Python One Time Password Library

LICENSE=	MIT

USES=		python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

do-test:
	@(cd ${WRKSRC}/${PORTNAME} && ${PYTHON_CMD} test.py)

.include <bsd.port.mk>
