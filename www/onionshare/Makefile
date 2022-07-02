PORTNAME=	onionshare
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2
PORTREVISION=	7
CATEGORIES=	www python security

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Secure and anonymous file sharing via Tor

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Depends on expired security/py-pycrypto
EXPIRATION_DATE=2022-09-30

RUN_DEPENDS=	tor:security/tor \
		obfs4proxy:security/obfs4proxy-tor \
		${PYTHON_PKGNAMEPREFIX}Flask>=0:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask-HTTPAuth>=0:security/py-flask-httpauth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycrypto>=0:security/py-pycrypto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysocks>=0:net/py-pysocks@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stem>=0:security/py-stem@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR}

USES=		cpe python:3.5+ pyqt:5
USE_GITHUB=	yes
GH_ACCOUNT=	micahflee
USE_PYQT=	pyqt5 sip
USE_PYTHON=	distutils autoplist noflavors

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' ${WRKSRC}/onionshare/common.py

.include <bsd.port.mk>
