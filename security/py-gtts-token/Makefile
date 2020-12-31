# $FreeBSD$

PORTNAME=	gtts-token
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.4
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Calculates a token to run the Google Translate text to speech

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Obsolete, please use audio/py-gtts instead
EXPIRATION_DATE=	2021-01-15

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR}

USES=		python:3.6+
USE_GITHUB=	yes
GH_ACCOUNT=	Boudewijn26
GH_PROJECT=	gTTS-token
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m unittest discover -v -s gtts_token/tests

.include <bsd.port.mk>
