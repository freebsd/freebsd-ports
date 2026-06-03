PORTNAME=	social-auth-core
DISTVERSION=	4.8.5
PORTREVISION=	4
CATEGORIES=	security www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	social_auth_core-${DISTVERSION}

PATCH_SITES=	https://github.com/python-social-auth/social-core/commit/
PATCHFILES=	44f15058c0b030b4f6212033f7db275739c86078.patch:-p1 \
		57105742439f046270c9dc404020620a5d4d7cdd.patch:-p1 \
		6496d8dd88ab99017dbe64f65b0058fd21e1bc90.patch:-p1 \
		9725f8f306beedc31062bfde359239740713f271.patch:-p1 \
		d447bd570e25b0a20ebc4687f48ca4d60718fafc.patch:-p1

MAINTAINER=	ultima@FreeBSD.org
COMMENT=	Social authentication/registration mechanism for several frameworks
WWW=		https://github.com/python-social-auth/social-core

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}defusedxml>=0.7.1:devel/py-defusedxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python3-openid>=3.2.0:security/py-python3-openid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyjwt>=2.11.0:www/py-pyjwt@${PY_FLAVOR} \
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

GOOGLE-ONETAP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}google-auth>=2.40.0<2.54:security/py-google-auth@${PY_FLAVOR}
SAML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python3-saml>=1.16.0:security/py-python3-saml@${PY_FLAVOR}

.include <bsd.port.mk>
