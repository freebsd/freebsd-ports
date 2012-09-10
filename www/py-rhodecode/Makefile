# New ports collection makefile for:	py-rhodecode
# Date created:		2012-04-21
# Whom:			gugabsd <gugabsd@mundounix.com.br>
#
# $FreeBSD$
#

PORTNAME=	rhodecode
PORTVERSION=	1.3.6
CATEGORIES=	www devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	RhodeCode-${PORTVERSION}

MAINTAINER=	gugabsd@mundounix.com.br
COMMENT=	Fast and powerful management tool for Mercurial and GIT

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pylons>=1.0:${PORTSDIR}/www/py-pylons \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy>=0.7.3:${PORTSDIR}/databases/py-sqlalchemy \
		${PYTHON_PKGNAMEPREFIX}pygments>=1.4:${PORTSDIR}/textproc/py-pygments \
		${PYTHON_PKGNAMEPREFIX}whoosh>=2.3.2:${PORTSDIR}/textproc/py-whoosh \
		${PYTHON_PKGNAMEPREFIX}Babel>=0.9.6:${PORTSDIR}/devel/py-babel \
		${PYTHON_PKGNAMEPREFIX}dateutil>=1.5:${PORTSDIR}/devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}dulwich>=0.8.5:${PORTSDIR}/devel/dulwich \
		${PYTHON_PKGNAMEPREFIX}docutils>=0.8.1:${PORTSDIR}/textproc/py-docutils \
		${PYTHON_PKGNAMEPREFIX}bcrypt>=0.2:${PORTSDIR}/security/py-bcrypt \
		${PYTHON_PKGNAMEPREFIX}PasteScript>=1.6.3:${PORTSDIR}/www/py-pastescript \
		${LOCALBASE}/bin/hg:${PORTSDIR}/devel/mercurial

USE_PYTHON=	2.6+
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	RhodeCode

OPTIONS_DEFINE=	LDAP GIT CELERY

GIT_DESC=	GIT support
CELERY_DESC=	Use Celery for better performance

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLDAP}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}ldap>=2.4.6:${PORTSDIR}/net/py-ldap2
.endif

.if ${PORT_OPTIONS:MGIT}
RUN_DEPENDS+=	${LOCALBASE}/bin/git:${PORTSDIR}/devel/git
.endif

.if ${PORT_OPTIONS:MCELERY}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}celery>=2.4.6:${PORTSDIR}/devel/py-celery
.endif

.include <bsd.port.mk>
