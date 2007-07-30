# New ports collection makefile for:	feedjack
# Date created:				Jul 28 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	feedjack
PORTVERSION=	0.9.7
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://static.tabo.aureal.com.pe/code/
DISTNAME=	Feedjack-${PORTVERSION}

MAINTAINER=	flz@FreeBSD.org
COMMENT=	Feed aggregator writen in Python using the Django framework

BUILD_DEPENDS=	easy_install:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/feedparser.py:${PORTSDIR}/textproc/py-feedparser \
		django-admin.py:${PORTSDIR}/www/py-django-devel

DIST_SUBDIR=	python
USE_PYTHON=	2.3+
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Feedjack
PYDISTUTILS_NOEGGINFO=	yes # XXX convert easy_install support to bsd.python.mk's

PLIST_SUB=	FEEDJACKVER=${PORTVERSION}	\
		PYTHONVER=${_PYTHON_VERSION}

.include <bsd.port.mk>
