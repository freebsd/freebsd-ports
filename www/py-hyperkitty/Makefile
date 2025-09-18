PORTNAME=	hyperkitty
PORTVERSION=	1.3.12
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	einar@isnic.is
COMMENT=	Web interface to access GNU Mailman v3 archives
WWW=		https://gitlab.com/mailman/hyperkitty

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pdm-backend>0:devel/py-pdm-backend@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django_compressor>=1.3:www/py-django_compressor@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-extensions>=1.3.7:www/py-django-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-gravatar2>=1.0.6:www/py-django-gravatar2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-haystack>=2.8.0:www/py-django-haystack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-q2>=1.0.0:www/py-django-q2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django42>=4.2:www/py-django42@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-mailman3>=1.3.13:mail/py-django-mailman3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}djangorestframework>=3.0.0:www/py-djangorestframework@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flufl.lock>=4.0:devel/py-flufl.lock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mailmanclient>=3.3.3:mail/py-mailmanclient@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mistune>=3.0:textproc/py-mistune@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>=2.0:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>=2.0:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}robot-detection>=0.3:www/py-robot-detection@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent pep517

SHEBANG_FILES=	hyperkitty/contrib/check_hk_import \
		hyperkitty/contrib/cleanarch3

NO_ARCH=	yes

post-extract:
	${RM} -rf ${WRKSRC}/example_project

.include <bsd.port.mk>
