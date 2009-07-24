# New ports collection makefile for:	feedjack
# Date created:				Jul 28 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	feedjack
PORTVERSION=	0.9.16
CATEGORIES=	www
MASTER_SITES=	http://www.feedjack.org/download/
DISTNAME=	Feedjack-${PORTVERSION}

MAINTAINER=	flz@FreeBSD.org
COMMENT=	Feed aggregator writen in Python using the Django framework

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/feedparser.py:${PORTSDIR}/textproc/py-feedparser \
		django-admin.py:${PORTSDIR}/www/py-django

DIST_SUBDIR=	python
USE_PYTHON=	2.3+
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	Feedjack

PLIST_SUB=	FEEDJACKVER=${PORTVERSION}	\
		PYTHONVER=${_PYTHON_VERSION}

.include <bsd.port.mk>
