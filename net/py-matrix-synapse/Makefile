# Created by: Brendan Molloy <brendan+freebsd@bbqsrc.net>
# $FreeBSD$

PORTNAME=	matrix-synapse
DISTVERSIONPREFIX=	v
DISTVERSION=	0.12.0
PORTREVISION=	1
CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	brendan+freebsd@bbqsrc.net
COMMENT=	Matrix protocol reference homeserver

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}frozendict>=0.4:devel/py-frozendict \
		${PYTHON_PKGNAMEPREFIX}unpaddedbase64>=1.0.1:devel/py-unpaddedbase64 \
		${PYTHON_PKGNAMEPREFIX}canonicaljson>=1.0.0:devel/py-canonicaljson \
		${PYTHON_PKGNAMEPREFIX}signedjson>=1.0.0:security/py-signedjson \
		${PYTHON_PKGNAMEPREFIX}pynacl>=0.3.0:security/py-pynacl \
		${PYTHON_PKGNAMEPREFIX}service_identity>=1.0.0:security/py-service_identity \
		${PYTHON_PKGNAMEPREFIX}twisted>=15.1.0:devel/py-twisted \
		${PYTHON_PKGNAMEPREFIX}openssl>=0.14:security/py-openssl \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml \
		${PYTHON_PKGNAMEPREFIX}pyasn1>0:devel/py-pyasn1 \
		${PYTHON_PKGNAMEPREFIX}daemonize>0:devel/py-daemonize \
		${PYTHON_PKGNAMEPREFIX}bcrypt>0:security/py-bcrypt \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow \
		${PYTHON_PKGNAMEPREFIX}pydenticon>0:devel/py-pydenticon \
		${PYTHON_PKGNAMEPREFIX}ujson>0:devel/py-ujson \
		${PYTHON_PKGNAMEPREFIX}blist>0:devel/py-blist \
		${PYTHON_PKGNAMEPREFIX}pysaml2>0:security/py-pysaml2 \
		${PYTHON_PKGNAMEPREFIX}pymacaroons-pynacl>0:security/py-pymacaroons-pynacl \
		${PYTHON_PKGNAMEPREFIX}simplejson>0:devel/py-simplejson \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}matrix-angular-sdk>0:devel/py-matrix-angular-sdk
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}virtualenv>0:devel/py-virtualenv \
		${PYTHON_PKGNAMEPREFIX}tox>0:devel/py-tox

USES=		python
USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils

GH_ACCOUNT=	matrix-org
GH_PROJECT=	synapse

NO_ARCH=	yes

do-test:
	# -epy27 added to skip running python packaging and other dist tests
	@(cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} ${TEST_TARGET} \
		-a "-epy27")

.include <bsd.port.mk>
