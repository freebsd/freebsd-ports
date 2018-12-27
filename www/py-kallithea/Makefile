# Created by: Ilia Skalozubov <freebsd@skinc.ru>
# $FreeBSD$

PORTNAME=	kallithea
PORTVERSION=	0.3.6
CATEGORIES=	www devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Kallithea-${PORTVERSION}

MAINTAINER=	freebsd@skinc.ru
COMMENT=	Fast and powerful management tool for Mercurial and Git

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}PasteScript>=1.6.3:www/py-pastescript@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}waitress>=0.8.8:www/py-waitress@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webob>=1.0.8:www/py-webob@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}WebTest>=1.4.3:www/py-WebTest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pylons>=1.0:www/py-pylons@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beaker>=1.6.4:www/py-beaker@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webhelpers>=1.3:www/py-webhelpers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}formencode>=1.2.4:www/py-formencode@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy10>=0.7.10:databases/py-sqlalchemy10@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mako>=0.9.0:textproc/py-mako@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=1.5:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}whoosh>=2.4.0:textproc/py-whoosh@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}celery>=2.2.5:devel/py-celery@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Babel>=0.9.6:devel/py-babel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.1:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown>=2.2.1:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docutils>=0.8.1:textproc/py-docutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urlobject>=2.3.4:www/py-urlobject@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}routes>=1.13:www/py-routes@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dulwich>=0.9.9:devel/dulwich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bcrypt>=0.3.0:security/py-bcrypt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bleach>=2.1.3:www/py-bleach@${PY_FLAVOR} \
		mercurial>=2.9:devel/mercurial

USES=		python:2.7 shebangfix
USE_PYTHON=	distutils autoplist

SHEBANG_FILES=	kallithea/tests/scripts/manual_test_crawler.py

NO_ARCH=	yes

USE_RC_SUBR=	kallithea
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	GIT LDAP
GIT_DESC=	Git repositories support

GIT_RUN_DEPENDS=	git:devel/git
LDAP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ldap:net/py-ldap@${PY_FLAVOR}

.include <bsd.port.mk>
