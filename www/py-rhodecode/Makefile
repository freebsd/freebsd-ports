# Created by: gugabsd <gugabsd@mundounix.com.br>
# $FreeBSD$

PORTNAME=	rhodecode
PORTVERSION=	1.7.2
PORTREVISION=	1
CATEGORIES=	www devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	RhodeCode-${PORTVERSION}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Fast and powerful management tool for Mercurial and GIT

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}PasteScript>=1.6.3:www/py-pastescript
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pylons>=1.0:www/py-pylons \
		${PYTHON_PKGNAMEPREFIX}waitress>=0.8.4:www/py-waitress \
		${PYTHON_PKGNAMEPREFIX}webob>=1.0.8:www/py-webob \
		${PYTHON_PKGNAMEPREFIX}formencode>=1.2.4:www/py-formencode \
		${PYTHON_PKGNAMEPREFIX}webhelpers>=1.3:www/py-webhelpers \
		${PYTHON_PKGNAMEPREFIX}mako>=0.7.3:textproc/py-mako \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy07>=0.7.10:databases/py-sqlalchemy07 \
		${PYTHON_PKGNAMEPREFIX}pygments>=1.5:textproc/py-pygments \
		${PYTHON_PKGNAMEPREFIX}whoosh>=2.4.0:textproc/py-whoosh \
		${PYTHON_PKGNAMEPREFIX}Babel>=0.9.6:devel/py-babel \
		${PYTHON_PKGNAMEPREFIX}dateutil>=1.5:devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}dulwich>=0.8.7:devel/dulwich \
		${PYTHON_PKGNAMEPREFIX}markdown>=2.2.1:textproc/py-markdown \
		${PYTHON_PKGNAMEPREFIX}docutils>=0.8.1:textproc/py-docutils \
		${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock \
		${PYTHON_PKGNAMEPREFIX}bcrypt>=0.2:security/py-bcrypt \
		${PYTHON_PKGNAMEPREFIX}simplejson>=2.5.2:devel/py-simplejson \
		${PYTHON_PKGNAMEPREFIX}PasteScript>=1.6.3:www/py-pastescript \
		${PYTHON_PKGNAMEPREFIX}pytz>=0:devel/py-pytz \
		${PYTHON_PKGNAMEPREFIX}repoze.lru>=0:devel/py-repoze.lru \
		${PYTHON_PKGNAMEPREFIX}celery>=0:devel/py-celery \
		mercurial>=2.6:devel/mercurial

USES=		python:2
USE_PYTHON=	distutils autoplist

USE_RC_SUBR=		rhodecode
SUB_FILES=		pkg-message

OPTIONS_DEFINE=		LDAP GIT
OPTIONS_DEFAULT=	GIT

GIT_DESC=	GIT support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLDAP}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}ldap>=2.4.6:net/py-ldap
.endif

.if ${PORT_OPTIONS:MGIT}
RUN_DEPENDS+=	${LOCALBASE}/bin/git:devel/git
.endif

.include <bsd.port.mk>
