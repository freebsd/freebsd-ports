# Created by: Ilia Skalozubov <freebsd@skinc.ru>
# $FreeBSD$

PORTNAME=	kallithea
PORTVERSION=	0.3.2
PORTREVISION=	1
CATEGORIES=	www devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Kallithea-${PORTVERSION}

MAINTAINER=	freebsd@skinc.ru
COMMENT=	Fast and powerful management tool for Mercurial and Git

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}PasteScript>=1.6.3:www/py-pastescript
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}waitress>=0.8.8:www/py-waitress \
		${PYTHON_PKGNAMEPREFIX}webob>=1.0.8:www/py-webob \
		${PYTHON_PKGNAMEPREFIX}WebTest>=1.4.3:www/py-WebTest \
		${PYTHON_PKGNAMEPREFIX}pylons>=1.0:www/py-pylons \
		${PYTHON_PKGNAMEPREFIX}beaker>=1.6.4:www/py-beaker \
		${PYTHON_PKGNAMEPREFIX}webhelpers>=1.3:www/py-webhelpers \
		${PYTHON_PKGNAMEPREFIX}formencode>=1.2.4:www/py-formencode \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy07>=0.7.10:databases/py-sqlalchemy07 \
		${PYTHON_PKGNAMEPREFIX}mako>=0.9.0:textproc/py-mako \
		${PYTHON_PKGNAMEPREFIX}pygments>=1.5:textproc/py-pygments \
		${PYTHON_PKGNAMEPREFIX}whoosh>=2.4.0:textproc/py-whoosh \
		${PYTHON_PKGNAMEPREFIX}celery>=2.2.5:devel/py-celery \
		${PYTHON_PKGNAMEPREFIX}Babel>=0.9.6:devel/py-babel \
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.1:devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}markdown>=2.2.1:textproc/py-markdown \
		${PYTHON_PKGNAMEPREFIX}docutils>=0.8.1:textproc/py-docutils \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock \
		${PYTHON_PKGNAMEPREFIX}urlobject>=2.3.4:www/py-urlobject \
		${PYTHON_PKGNAMEPREFIX}routes>=1.13:www/py-routes \
		${PYTHON_PKGNAMEPREFIX}dulwich>=0.9.9:devel/dulwich \
		${PYTHON_PKGNAMEPREFIX}bcrypt>=0.3.0:security/py-bcrypt \
		mercurial>=2.9:devel/mercurial

USES=		python:2.7
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

USE_RC_SUBR=	kallithea
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	GIT LDAP
GIT_DESC=	Git repositories support

GIT_RUN_DEPENDS=	git:devel/git
LDAP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ldap:net/py-ldap

.include <bsd.port.mk>
