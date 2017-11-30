# Created by: Ilia Skalozubov <freebsd@skinc.ru>
# $FreeBSD$

PORTNAME=	kallithea
PORTVERSION=	0.3.2
PORTREVISION=	2
CATEGORIES=	www devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Kallithea-${PORTVERSION}

MAINTAINER=	freebsd@skinc.ru
COMMENT=	Fast and powerful management tool for Mercurial and Git

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}PasteScript>=1.6.3:www/py-pastescript@${FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}waitress>=0.8.8:www/py-waitress@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webob>=1.0.8:www/py-webob@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}WebTest>=1.4.3:www/py-WebTest@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pylons>=1.0:www/py-pylons@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beaker>=1.6.4:www/py-beaker@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webhelpers>=1.3:www/py-webhelpers@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}formencode>=1.2.4:www/py-formencode@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy10>=0.7.10:databases/py-sqlalchemy10@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mako>=0.9.0:textproc/py-mako@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=1.5:textproc/py-pygments@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}whoosh>=2.4.0:textproc/py-whoosh@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}celery>=2.2.5:devel/py-celery@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Babel>=0.9.6:devel/py-babel@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.1:devel/py-dateutil@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown>=2.2.1:textproc/py-markdown@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docutils>=0.8.1:textproc/py-docutils@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urlobject>=2.3.4:www/py-urlobject@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}routes>=1.13:www/py-routes@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dulwich>=0.9.9:devel/dulwich \
		${PYTHON_PKGNAMEPREFIX}bcrypt>=0.3.0:security/py-bcrypt@${FLAVOR} \
		mercurial>=2.9:devel/mercurial

USES=		python:2.7
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

USE_RC_SUBR=	kallithea
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	GIT LDAP
GIT_DESC=	Git repositories support

GIT_RUN_DEPENDS=	git:devel/git
LDAP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ldap:net/py-ldap@${FLAVOR}

.include <bsd.port.mk>
