# Ports collection makefile for:	py-Pootle
# Date created:			Sept 3, 2010
# Whom:				jpaetzel
#
# $FreeBSD$
#

PORTNAME=	Pootle
PORTVERSION=	2.1.1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	translate/${PORTNAME}/${PORTVERSION}/
PKGNAMEPREFIX=  ${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jpaetzel@FreeBSD.org
COMMENT=	Python Translation Suite

USE_PYTHON=	yes
USE_BZIP2=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	${PORTNAME}

RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/South-0.7.1-py2.6.egg:${PORTSDIR}/databases/py-south \
		${PYTHON_SITELIBDIR}/translate:${PORTSDIR}/textproc/translate-toolkit \
		${PYTHON_SITELIBDIR}/django/bin/django-admin.py:${PORTSDIR}/www/py-django

OPTIONS=	MYSQL	"MYSQL support"		on \
		SUBVERSION	"SVN support"	on \
		LUCENE "py-lucene for faster searching" on \
		MEMCACHED "Enable memcached support"	on

.include <bsd.port.pre.mk>

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
.endif

.if defined(WITH_SUBVERSION)
RUN_DEPENDS+=   svn:${PORTSDIR}/devel/subversion
.endif

.if defined(WITH_LUCENE)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/lucene/_lucene.so:${PORTSDIR}/textproc/py-lucene
.endif

.if defined(WITH_MEMCACHED)
LIB_DEPENDS+=	memcached:${PORTSDIR}/databases/libmemcached
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/python_memcached-1.45-py2.6.egg:${PORTSDIR}/databases/py-memcached
.endif

.include <bsd.port.post.mk>
