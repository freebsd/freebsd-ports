PORTNAME=	social-auth-core
DISTVERSION=	4.0.2
CATEGORIES=	security www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ultima@FreeBSD.org
COMMENT=	Social authentication/registration mechanism for several frameworks

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cryptography>=2.1.1:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}defusedxml>=0.5.0:devel/py-defusedxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python3-openid>=3.0.10:security/py-python3-openid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyjwt>=1.7.1:www/py-pyjwt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oauthlib>=1.0.3:security/py-oauthlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.9.1:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-oauthlib>=0.6.1:www/py-requests-oauthlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six@${PY_FLAVOR}

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=4.5:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpretty>=0.9.6:www/py-httpretty@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}coverage>=3.6:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=2.7.1:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}unittest2>0:devel/py-unittest2@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

OPTIONS_DEFINE=	OPENID SAML
OPTIONS_DEFAULT=	OPENID SAML

OPENID_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-jose>=3.0.0:security/py-python-jose@${PY_FLAVOR}
OPENID_DESC?=	OpenID connect Support

SAML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python3-saml>=1.2.1:security/py-python3-saml@${PY_FLAVOR}
SAML_DESC?=	SAML Support

do-test:
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest -v

.include <bsd.port.mk>
