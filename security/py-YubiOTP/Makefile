# Created by: Carlo Strub <cs@FreeBSD.org>

PORTNAME=	YubiOTP
PORTVERSION=	1.0.0
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Library for verifying YubiKey OTP tokens

LICENSE=	BSD2CLAUSE

DEPRECATED=	Depends on expired security/py-pycrypto
EXPIRATION_DATE=2022-09-30

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycrypto>0:security/py-pycrypto@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
