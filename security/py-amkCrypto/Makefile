# New ports collection makefile for:	py-amkCrypto
# Date created:				19 April 2001
# Whom:					Jason R. Mastaler <jason@mastaler.com>
#
# $FreeBSD$
#

PORTNAME=	amkCrypto
PORTVERSION=	0.1.3
CATEGORIES=	security python
MASTER_SITES=	http://www.amk.ca/files/python/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
EXTRACT_SUFX=	.tgz

MAINTAINER=	jason@mastaler.com

BUILD_DEPENDS=	${PYDISTUTILS}
USE_PYTHON=	yes
USE_OPENSSL=	yes

do-build:
	(cd ${WRKSRC}; ${PYTHON_CMD} setup.py build)

do-install:
	(cd ${WRKSRC}; ${PYTHON_CMD} setup.py install)

.include <bsd.port.mk>
