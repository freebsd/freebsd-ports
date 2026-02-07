PORTNAME=	gpiozero
DISTVERSION=	2.0.1
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simple interface to GPIO devices with Raspberry Pi
WWW=		https://gpiozero.readthedocs.io/en/latest/ \
		https://github.com/gpiozero/gpiozero

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

ONLY_FOR_ARCHS=		aarch64
ONLY_FOR_ARCHS_REASON=	intended only for Raspberry Pi

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
