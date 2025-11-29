PORTNAME=	social-auth-core
DISTVERSION=	4.8.1
PORTREVISION=	1
CATEGORIES=	security www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	social_auth_core-${DISTVERSION}

PATCH_SITES=	https://github.com/python-social-auth/social-core/commit/
PATCHFILES=	aabb5db20fd2f18e3874edf78168caee1a9ea792.patch:-p1 \
		09051177196dc64a250d963a58983b4d28db7c2d.patch:-p1

MAINTAINER=	ultima@FreeBSD.org
COMMENT=	Social authentication/registration mechanism for several frameworks
WWW=		https://github.com/python-social-auth/social-core

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}defusedxml>=0.7.1:devel/py-defusedxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python3-openid>=3.2.0:security/py-python3-openid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyjwt>=2.10.1:www/py-pyjwt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oauthlib>=3.3.1:security/py-oauthlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.32.5:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-oauthlib>=2.0.0:www/py-requests-oauthlib@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}responses>=0.25.0:devel/py-responses@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist cryptography pep517 pytest

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

# An SHOPIFY option would still be possible as well, but the ports tree does
# not yet have all the required dependencies for this.
OPTIONS_DEFINE=		GOOGLE-ONETAP SAML
OPTIONS_DEFAULT=	GOOGLE-ONETAP SAML

GOOGLE-ONETAP_DESC=	Google One Tap support
SAML_DESC?=	SAML Support

GOOGLE-ONETAP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}google-auth>=2.40.0<2.44:security/py-google-auth@${PY_FLAVOR}
SAML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python3-saml>=1.16.0:security/py-python3-saml@${PY_FLAVOR}

.include <bsd.port.mk>
