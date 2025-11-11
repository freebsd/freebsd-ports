PORTNAME=	unmessage
DISTVERSION=	0.2.0
PORTREVISION=	8
CATEGORIES=	net-im net-p2p python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Privacy enhanced instant messenger
WWW=		https://github.com/AnemoneLabs/unmessage

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	tor:security/tor \
		${PYTHON_PKGNAMEPREFIX}opuslib>=1.1.0:audio/py-opuslib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyaudio>=0.2.10:audio/py-pyaudio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyaxo>=0.7.3:security/py-pyaxo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pynacl>=1.0.1:security/py-pynacl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyperclip>=1.5.27:devel/py-pyperclip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}twisted>=16.6.0:devel/py-twisted@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}txtorcon>=0.19.0:security/py-txtorcon@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tkinter>0:x11-toolkits/py-tkinter@${PY_FLAVOR}
# Twisted[tls]
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pyopenssl>=16.0.0:security/py-pyopenssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}service-identity>0:security/py-service-identity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}idna>=0.6:dns/py-idna@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
