PORTNAME=	certbot-dns-standalone
PORTVERSION=	1.1
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jamie@catflap.org
COMMENT=	Standalone DNS Authenticator plugin for Certbot
WWW=		https://github.com/siilike/certbot-dns-standalone

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}acme>=${ACME_VERSION},1:security/py-acme@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certbot>=${ACME_VERSION},1:security/py-certbot@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dnslib>=0.9.0:dns/py-dnslib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>5.0.0:devel/py-mock@${PY_FLAVOR} \

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include "${.CURDIR}/../py-acme/version.mk"
.include <bsd.port.mk>
