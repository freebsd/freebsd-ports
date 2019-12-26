# Created by: gugabsd <gugabsd@mundounix.com.br>
# $FreeBSD$

PORTNAME=	rhodecode
PORTVERSION=	1.7.2
PORTREVISION=	3
CATEGORIES=	www devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	RhodeCode-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast and powerful management tool for Mercurial and GIT

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}PasteScript>=1.6.3:www/py-pastescript@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pylons>=1.0:www/py-pylons@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}waitress>=0.8.4:www/py-waitress@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webob>=1.0.8:www/py-webob@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}formencode>=1.2.4:www/py-formencode@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webhelpers>=1.3:www/py-webhelpers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mako>=0.7.3:textproc/py-mako@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy10>=0.7.10:databases/py-sqlalchemy10@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=1.5:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}whoosh>=2.4.0:textproc/py-whoosh@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Babel>=0.9.6:devel/py-babel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=1.5:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dulwich>=0.8.7:devel/dulwich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown>=2.2.1:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docutils>=0.8.1:textproc/py-docutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bcrypt>=0.2:security/py-bcrypt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}simplejson>=2.5.2:devel/py-simplejson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PasteScript>=1.6.3:www/py-pastescript@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=0:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}repoze.lru>=0:devel/py-repoze.lru@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}celery>=0:devel/py-celery@${PY_FLAVOR} \
		mercurial>=2.6:devel/mercurial

USES=		python:2.7
USE_PYTHON=	distutils autoplist

USE_RC_SUBR=		rhodecode
SUB_FILES=		pkg-message

OPTIONS_DEFINE=		LDAP GIT
OPTIONS_DEFAULT=	GIT

GIT_DESC=	GIT support

LDAP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ldap>=2.4.6:net/py-ldap@${PY_FLAVOR}
GIT_RUN_DEPENDS=	git:devel/git

.include <bsd.port.mk>
