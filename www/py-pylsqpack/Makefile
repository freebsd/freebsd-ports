# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	pylsqpack
PORTVERSION=	0.3.14
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python wrapper for the ls-qpack QPACK library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++11-lang python:3.7+
USE_PYTHON=	autoplist concurrent distutils

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

do-test:
	cd ${WRKSRC} && ${PYTHON_CMD} -m unittest -v

.include <bsd.port.mk>
