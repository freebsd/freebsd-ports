PORTNAME=	django-otp-yubikey
PORTVERSION=	1.1.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	django_otp_yubikey-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Django-otp plugin that verifies YubiKey OTP tokens
WWW=		https://django-otp-yubikey.readthedocs.io/en/latest/ \
		https://github.com/django-otp/django-otp-yubikey

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django-otp>=1.0<2:www/py-django-otp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}YubiOTP>=1.0<2:security/py-YubiOTP@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
