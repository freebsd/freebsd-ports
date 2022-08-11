PORTNAME=	pwman3
PORTVERSION=	0.0.6
PORTREVISION=	2
CATEGORIES=	security python
MASTER_SITES=	http://pwman.bleurgh.com/~ivan/pwman3/source/ \
		http://source.antisupport.com/pwman3/
DISTNAME=	Pwman3-${PORTVERSION}

MAINTAINER=	yarodin@gmail.com
COMMENT=	Console password management application with sql storage

DEPRECATED=	Depends on expired security/py-pycrypto
EXPIRATION_DATE=2022-09-30

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycrypto>=2.0:security/py-pycrypto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist concurrent optsuffix

NO_ARCH=	yes

.include <bsd.port.mk>
