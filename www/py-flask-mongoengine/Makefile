PORTNAME=	flask-mongoengine
PORTVERSION=	1.0.0
DISTVERSIONPREFIX=	v
CATEGORIES=	www devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	meka@tilda.center
COMMENT=	Flask extension that provides integration with MongoEngine

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Flask>=0:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask-WTF>=0:www/py-flask-wtf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mongoengine>=0:databases/py-mongoengine@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>=0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest-cov@${PY_FLAVOR}

USES=		python:3.5+
USE_GITHUB=	yes # tests not packaged with PyPI sdist
GH_ACCOUNT=	MongoEngine
USE_PYTHON=	autoplist concurrent distutils

TEST_ENV=	PYTHONPATH=${WRKSRC}/src

NO_ARCH=	yes

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest -v -rs -o addopts= \
		-k 'not test_with_id \
		and not test_basic_insert \
		and not test_multiple_connections \
		and not test_binaryfield \
		and not test_choices_coerce \
		and not test_list_choices_coerce \
		and not test_emailfield \
		and not test_model_form \
		and not test_model_form_only \
		and not test_model_form_with_custom_query_set \
		and not test_modelselectfield \
		and not test_modelselectfield_multiple \
		and not test_modelselectfield_multiple_initalvalue_None \
		and not test_modelradiofield \
		and not test_passwordfield \
		and not test_unique_with \
		and not test_sub_field_args \
		and not test_modelselectfield_multiple_selected_elements_must_be_retained \
		and not test_model_form_help_text \
		and not test_shared_field_args \
		and not test_embedded_model_form \
		and not test_form_label_modifier \
		and not test_inheritance \
		and not test_with_id \
		and not test_basic_insert \
		and not test_queryset_paginator \
		and not test_list_field_pagination \
		and not test_setting_session'

.include <bsd.port.mk>
