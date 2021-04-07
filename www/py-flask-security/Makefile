PORTNAME=	flask-security
PORTVERSION=	3.0.0
PORTREVISION=	1
CATEGORIES=	www devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Flask-Security-${DISTVERSION}

MAINTAINER=	meka@tilda.center
COMMENT=	Simple security for Flask apps

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-runner>=0:devel/py-pytest-runner@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Babel>=0:devel/py-babel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Flask>=0:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask-Login>=0:www/py-flask-login@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask-Mail>=0:mail/py-flask-mail@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask-Principal>=0:www/py-flask-principal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask-WTF>=0:www/py-flask-wtf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask-babelex>=0:www/py-flask-babelex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}itsdangerous>=0:security/py-itsdangerous@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}passlib>=0:security/py-passlib@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flask-sqlalchemy>=0:databases/py-flask-sqlalchemy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bcrypt>=0:security/py-bcrypt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}check-manifest>=0:devel/py-check-manifest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}coverage>=0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}isort>=0:devel/py-isort@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mongoengine>=0:databases/py-mongoengine@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydocstyle>=0:devel/py-pydocstyle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cache>=0:devel/py-pytest-cache@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-flakes>=0:devel/py-pytest-flakes@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy12>=0:databases/py-sqlalchemy12@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-translations>=0:devel/py-pytest-translations@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-pep8>=0:devel/py-pytest-pep8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask-peewee>=0:www/py-flask-peewee@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pony>=0:databases/py-pony@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask-mongoengine>=0:www/py-flask-mongoengine@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-flakes>=0:devel/py-pytest-flakes@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyflakes>=0:devel/py-pyflakes@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

TEST_ENV=	PYTHONPATH=${WRKSRC}/src

NO_ARCH=	yes

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest -v -rs -o addopts= \
		-k 'not test_disable_register_emails \
		and not test_custom_register_tempalate \
		and not test_custom_register_url \
		and not test_registerable_flag \
		and not test_custom_reset_templates \
		and not test_custom_reset_url \
		and not test_expired_reset_token \
		and not test_expired_login_token \
		and not test_without_babel \
		and not test_password_unicode_password_salt \
		and not test_custom_change_url \
		and not test_view_configuration \
		and not test_template_configuration \
		and not test_login_when_unconfirmed \
		and not test_passwordless_login_context_processor \
		and not test_expired_confirmation_token \
		and not test_confirmation_different_user_when_logged_in \
		and not test_cannot_reset_password_when_email_is_not_confirmed \
		and not test_context_processors \
		and not test_custom_change_template \
		and not test_disable_change_emails \
		and not test_custom_post_change_view \
		and not test_context_processors \
		and not test_legacy_hash'

.include <bsd.port.mk>
