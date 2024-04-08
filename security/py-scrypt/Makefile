PORTNAME=	scrypt
DISTVERSION=	0.8.24
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Bindings for the scrypt key derivation function library
WWW=		https://pypi.org/project/scrypt/

LICENSE=	BSD2CLAUSE

USES=		python ssl
USE_PYTHON=	autoplist distutils pytest

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/_scrypt*.so

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
