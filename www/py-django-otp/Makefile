PORTNAME=	django-otp
PORTVERSION=	1.6.1
CATEGORIES=	www python
MASTER_SITES=	PYPI
DISTNAME=	django_otp-${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Pluggable framework for adding two-factor authentication to Django
WWW=		https://github.com/django-otp/django-otp

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>=4.2:www/py-django42@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_RADIO=	QR
OPTIONS_RADIO_QR=	QRCODE SEGNO
QRCODE_DESC=	QR code support via qrcode module
SEGNO_DESC=	QR code support via segno module

QRCODE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}qrcode>=0:textproc/py-qrcode@${PY_FLAVOR}
SEGNO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}segno>=0:textproc/py-segno@${PY_FLAVOR}

.include <bsd.port.mk>
