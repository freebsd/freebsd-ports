# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	certbot
PORTVERSION=	${ACME_VERSION}
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Let's Encrypt client #'

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}acme>=${ACME_VERSION},1:security/py-acme@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}configargparse>=0.9.3:devel/py-configargparse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}configobj>0:devel/py-configobj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>=1.2:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}josepy>=0:security/py-josepy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}parsedatetime>=1.3:devel/py-parsedatetime@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>0:security/py-openssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyrfc3339>0:devel/py-pyrfc3339@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=1.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.component>0:devel/py-zope.component@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>0:devel/py-zope.interface@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR}

# Actually 2.7,3.3+
USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} \
		-e 's|/etc/|${LOCALBASE}/etc/|' \
		-e 's|/var/lib|/var/db|' \
		${WRKSRC}/${PORTNAME}/constants.py

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include "${.CURDIR}/../py-acme/version.mk"
.include <bsd.port.mk>
