PORTNAME=	SimpleSoapy
DISTVERSION=	1.5.1
PORTREVISION=	4
CATEGORIES=	misc hamradio python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simple pythonic wrapper for SoapySDR library
WWW=		https://github.com/xmikos/simplesoapy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}SoapySDR>0:misc/py-SoapySDR@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
