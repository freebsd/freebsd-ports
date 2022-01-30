PORTNAME=	ldap0
PORTVERSION=	1.4.7
CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	Module package for implementing LDAP clients

LICENSE=	PSFL

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyasn1>=0.4.5:devel/py-pyasn1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyasn1-modules>=0.2.5:devel/py-pyasn1-modules@${PY_FLAVOR}
# Cyrus needs PLAIN / CRAM-MD5 / DIGEST-MD5 enabled
TEST_DEPENDS=	${LOCALBASE}/libexec/slapd:net/openldap24-server

USES=		localbase python:3.6+
USE_LOCALE=	en_US.UTF-8
USE_OPENLDAP=	yes
USE_PYTHON=	autoplist distutils

USE_GITLAB=	yes
GL_ACCOUNT=	ae-dir
GL_PROJECT=	python-ldap0
GL_COMMIT=	70b3aad8593d34c82f6bca1eca53f1c8938d345d

PYDISTUTILS_BUILD_TARGET=	build_ext
PYDISTUTILS_BUILDARGS+=		--inplace

# Add LOGLEVEL=DEBUG to debug tests
TEST_ENV=	LDAPNOINIT=1 \
		SLAPD=${LOCALBASE}/libexec/slapd \
		SCHEMA=${LOCALBASE}/etc/openldap/schema \
		BIN=${LOCALBASE}/bin \
		SBIN=${LOCALBASE}/sbin \
		TMP=${WRKDIR}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/_libldap0*.so

do-test:
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
