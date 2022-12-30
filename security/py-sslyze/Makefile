PORTNAME=	sslyze
PORTVERSION=	5.0.5
PORTREVISION=	3
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast and powerful SSL/TLS scanning library
WWW=		https://github.com/nabla-c0d3/sslyze

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cryptography>=2.6,1<39.0.0,1:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nassl>=4.0.1<5.0.0:security/py-nassl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic>=1.7<1.11:devel/py-pydantic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tls-parser>=2.0.0<3.0.0:security/py-tls-parser@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

post-patch:
	@${RM} ${WRKSRC}/sslyze/plugins/openssl_cipher_suites/_tls12_workaround.py

.include <bsd.port.mk>
