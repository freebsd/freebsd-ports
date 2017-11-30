# $FreeBSD$

PORTNAME=	treq
PORTVERSION=	17.8.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	asomers@FreeBSD.org
COMMENT=	Requests-like API built on top of twisted.web's Agent

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}incremental>=0:devel/py-incremental@${FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>=0:devel/py-attrs@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}twisted>=16.4.0:devel/py-twisted@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.1.0:www/py-requests@${FLAVOR}
# Depend directly on twisted[tls] dependencies
# As Twisted port may not (optionally) install them
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}openssl>=16.0.0:security/py-openssl@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}service_identity>=16.0.0:security/py-service_identity@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}idna>=2.4:dns/py-idna@${FLAVOR}

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock@${FLAVOR}

USES=		python:2.7+	# Actually 2.7+,3.3+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m twisted.trial treq

.include <bsd.port.mk>
