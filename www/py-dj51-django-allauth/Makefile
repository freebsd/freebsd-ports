PORTNAME=	django-allauth
PORTVERSION=	65.11.0
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj51-
DISTNAME=	${PORTNAME:S/-/_/}-${PORTVERSION}

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	User registration with social account authentication
WWW=		https://allauth.org/ \
		https://docs.allauth.org/en/latest/ \
		https://github.com/pennersr/django-allauth

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=63.0.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=8:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fido2>=0:security/py-fido2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django51>=5.1:www/py-django51@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	MFA OPENID SAML SOCIALACCOUNT STEAM
OPTIONS_DEFAULT=MFA OPENID SOCIALACCOUNT
MFA_DESC=		Multi-Factor Authentication support
OPENID_DESC=		OpenID authentication support
SAML_DESC=		Security Assertion Markup Language support
SOCIALACCOUNT_DESC=	Social network account support
STEAM_DESC=		Steam OpenID authentication support

MFA_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}qrcode>=7.0.0:textproc/py-qrcode@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}fido2>=0:security/py-fido2@${PY_FLAVOR}
OPENID_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python3-openid>=3.0.8:security/py-python3-openid@${PY_FLAVOR}
SAML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python3-saml>=1.15.0<2.0.0:security/py-python3-saml@${PY_FLAVOR}
SOCIALACCOUNT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyjwt>=1.7:www/py-pyjwt@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}requests-oauthlib>=0.3.0:www/py-requests-oauthlib@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}requests>=2.0.0:www/py-requests@${PY_FLAVOR}
STEAM_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python3-openid>=3.0.8:security/py-python3-openid@${PY_FLAVOR}

.include <bsd.port.mk>
