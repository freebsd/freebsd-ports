PORTNAME=	social-auth-app-django
DISTVERSION=	5.5.1
CATEGORIES=	www security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj51-

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Social Authentication and Django integration
WWW=		https://github.com/python-social-auth/social-app-django

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django51>=5.1:www/py-django51@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}social-auth-core>=4.4<5:security/py-social-auth-core@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR}

USES=		python:3.10+
USE_GITHUB=	yes
GH_ACCOUNT=	python-social-auth
GH_PROJECT=	social-app-django
USE_PYTHON=	autoplist pep517

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*${PORTNAME}

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} manage.py test -v3

.include <bsd.port.mk>
