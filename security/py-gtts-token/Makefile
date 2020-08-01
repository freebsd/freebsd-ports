# $FreeBSD$

PORTNAME=	gtts-token
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.3
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Calculates a token to run the Google Translate text to speech

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	Boudewijn26
GH_PROJECT=	gTTS-token
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m unittest discover -v -s gtts_token/tests

.include <bsd.port.mk>
