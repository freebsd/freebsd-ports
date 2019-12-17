# $FreeBSD$

PORTNAME=	pecan
PORTVERSION=	1.3.3
CATEGORIES=	www python net
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wjw@digiware.nl
COMMENT=	WSGI object-dispatching web framework

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}webob>=1.2:www/py-webob@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mako>=0.4.0:textproc/py-mako@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}WebTest>=1.3.1:www/py-WebTest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}logutils>=0.3:devel/py-logutils@${PY_FLAVOR}

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gunicorn>=0:www/py-gunicorn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy10>=0:databases/py-sqlalchemy10@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist concurrent

NO_ARCH=	yes

do-test:
	@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} setup.py test)

.include <bsd.port.pre.mk>

.if ${PYTHON_VER} < 3.4
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}singledispatch>=0:devel/py-singledispatch@${PY_FLAVOR}
.endif

.if ${PYTHON_VER} < 3.0
TEST_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}Genshi>=0:textproc/py-genshi@${PY_FLAVOR}
# To be ported
# 		${PYTHON_PKGNAMEPREFIX}kajiki>0:textproc/py-kajiki@${PY_FLAVOR}
.else
# Genshi added Python3 (< 3.5) support in 0.7
TEST_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}Genshi>=0.7:textproc/py-genshi@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
