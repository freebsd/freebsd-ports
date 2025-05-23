PORTNAME=	exscript
DISTVERSIONPREFIX=	v
DISTVERSION=	2.6
PORTREVISION=	2
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jhay@FreeBSD.org
COMMENT=	Automating Telnet and SSH
WWW=		https://github.com/knipknap/exscript

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}configparser>0:devel/py-configparser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paramiko>0:security/py-paramiko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycryptodomex>0:security/py-pycryptodomex@${PY_FLAVOR}

USES=		python
# Upstream doesn't provide a sdist, yet
USE_GITHUB=	yes
GH_ACCOUNT=	knipknap
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e \
		"{s#__version__ = '[^']*'#__version__ = '${PORTVERSION}'#;}" \
		${BUILD_WRKSRC}/VERSION.in ${BUILD_WRKSRC}/Exscript/version.py

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m unittest discover -v tests/Exscript "*Test.py"

.include <bsd.port.mk>
