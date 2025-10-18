PORTNAME=	django-allauth
PORTVERSION=	65.12.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	django_allauth-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	User registration with social account authentication
WWW=		https://allauth.org/ \
		https://docs.allauth.org/en/latest/ \
		https://codeberg.org/allauth/django-allauth

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.0.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=8:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asgiref>=3.8.1:www/py-asgiref@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django42>=4.2.16:www/py-django42@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	HEADLESS_SPEC IDP_OIDC MFA OPENID SAML SOCIALACCOUNT STEAM
OPTIONS_DEFAULT=HEADLESS_SPEC IDP_OIDC MFA OPENID SAML SOCIALACCOUNT STEAM
HEADLESS_SPEC_DESC=	Single-page and mobile application support
IDP_OIDC_DESC=		Identity provider functionality with OpenID Connect support
MFA_DESC=		Multi-Factor Authentication support
OPENID_DESC=		OpenID authentication support
SAML_DESC=		Security Assertion Markup Language support
SOCIALACCOUNT_DESC=	Social network account support
STEAM_DESC=		Steam OpenID authentication support

HEADLESS_SPEC_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyyaml>=6<7:devel/py-pyyaml@${PY_FLAVOR}
IDP_OIDC_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}oauthlib>=3.3.0<4:security/py-oauthlib@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pyjwt>=2.0<3:www/py-pyjwt@${PY_FLAVOR}
MFA_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fido2>=1.1.2<3:security/py-fido2@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}qrcode>=7.0.0<9:textproc/py-qrcode@${PY_FLAVOR}
OPENID_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python3-openid>=3.0.8<4:security/py-python3-openid@${PY_FLAVOR}
SAML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python3-saml>=1.15.0<2.0.0:security/py-python3-saml@${PY_FLAVOR}
SOCIALACCOUNT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}oauthlib>=3.3.0<4:security/py-oauthlib@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}pyjwt>=2.0<3:www/py-pyjwt@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}requests>=2.0.0<3:www/py-requests@${PY_FLAVOR}
STEAM_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python3-openid>=3.0.8<4:security/py-python3-openid@${PY_FLAVOR}

.include <bsd.port.mk>
