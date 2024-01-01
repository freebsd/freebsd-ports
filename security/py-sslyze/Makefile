PORTNAME=	sslyze
PORTVERSION=	5.2.0
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast and powerful SSL/TLS scanning library
WWW=		https://github.com/nabla-c0d3/sslyze

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nassl>=5.1<6:security/py-nassl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic>=1.10<2.4,1:devel/py-pydantic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>=23,1<24,1:security/py-openssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tls-parser>=2<3:security/py-tls-parser@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cryptography distutils

NO_ARCH=	yes

post-patch:
	@${RM} ${WRKSRC}/sslyze/plugins/openssl_cipher_suites/_tls12_workaround.py

.include <bsd.port.mk>
