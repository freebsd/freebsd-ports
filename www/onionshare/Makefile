# $FreeBSD$

PORTNAME=	onionshare
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.1
PORTREVISION=	1
CATEGORIES=	www python security

MAINTAINER=	egypcio@googlemail.com
COMMENT=	Secure and anonymous file sharing via Tor

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	tor:security/tor \
		obfs4proxy:security/obfs4proxy-tor \
		${PYTHON_PKGNAMEPREFIX}Flask>0:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stem>0:security/py-stem@${PY_FLAVOR}

USES=		python:3.4+ pyqt:5
USE_GITHUB=	yes
GH_ACCOUNT=	micahflee
USE_PYQT=	core gui sip widgets  # "sip" should be "sip_build", but "import PyQt5.QtCore" wants "sip". See bug#225040
USE_PYTHON=	distutils autoplist noflavors

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' ${WRKSRC}/onionshare/common.py

.include <bsd.port.mk>
