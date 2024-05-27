PORTNAME=	django-allauth
PORTVERSION=	0.59.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj42-

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	User registration with social account authentication
WWW=		https://allauth.org/ \
		https://docs.allauth.org/en/latest/ \
		https://github.com/pennersr/django-allauth

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Obsolete, please use www/py-django-allauth instead
EXPIRATION_DATE=2024-06-15

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=40.8.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>=3.2:www/py-django42@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyjwt>=1.7:www/py-pyjwt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python3-openid>=3.0.8:security/py-python3-openid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.0.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-oauthlib>=0.3.0:www/py-requests-oauthlib@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*${PORTNAME}

NO_ARCH=	yes

OPTIONS_DEFINE=	MFA SAML
MFA_DESC=	Multi-Factor Authentication support
SAML_DESC=	Security Assertion Markup Language support

MFA_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}qrcode>=7.0.0:textproc/py-qrcode@${PY_FLAVOR}
SAML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python3-saml>=1.15.0<2.0.0:security/py-python3-saml@${PY_FLAVOR}

.include <bsd.port.mk>
