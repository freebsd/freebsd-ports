# $FreeBSD$

PORTNAME=	pyotp
PORTVERSION=	2.1.0
CATEGORIES=	security
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	vlad-fbsd@acheronmedia.com
COMMENT=	Python One Time Password Library

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	pyotp
GH_PROJECT=	pyotp
GH_TAGNAME=	02ab049b2b473365bc7b57dc8dba14af71265895

USES=		python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

do-test:
	@(cd ${WRKSRC}/${PORTNAME} && ${PYTHON_CMD} test.py)

.include <bsd.port.mk>
