# Created by: Yuri Victorovich
# $FreeBSD$

PORTNAME=	unmessage
PORTVERSION=	0.2.0
CATEGORIES=	net-im net-p2p python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@rawbw.com
COMMENT=	Privacy enhanced instant messenger

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	tor:security/tor \
		${PYTHON_PKGNAMEPREFIX}opuslib>=1.1.0:audio/py-opuslib@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyaudio>=0.2.10:audio/py-pyaudio@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyaxo>=0.7.3:security/py-pyaxo@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pynacl>=1.0.1:security/py-pynacl@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyperclip>=1.5.27:devel/py-pyperclip@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}twisted>=16.6.0:devel/py-twisted@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}txtorcon>=0.19.0:security/py-txtorcon@${FLAVOR}

USES=		python:2.7
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
