PORTNAME=	django-otp-yubikey
PORTVERSION=	1.0.1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Django-otp plugin that verifies YubiKey OTP tokens
WWW=		https://github.com/django-otp/django-otp-yubikey

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django-otp>=1.0.0:www/py-django-otp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}YubiOTP>=0.2.2:security/py-YubiOTP@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
