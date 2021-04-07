PORTNAME=	soapy_power
DISTVERSION=	1.6.1
PORTREVISION=	2
CATEGORIES=	misc hamradio python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Obtain power spectrum from SoapySDR devices

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pyFFTW>0:math/py-pyFFTW@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}SimpleSoapy>=1.5.0:misc/py-SimpleSoapy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}SimpleSpectral>0:science/py-SimpleSpectral@${PY_FLAVOR}

USES=		python:3.4+
USE_PYTHON=	distutils concurrent autoplist

.include <bsd.port.mk>
