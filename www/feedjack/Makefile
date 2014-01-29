# $FreeBSD$

PORTNAME=	feedjack
PORTVERSION=	0.9.16
CATEGORIES=	www
MASTER_SITES=	http://www.feedjack.org/download/
DISTNAME=	Feedjack-${PORTVERSION}

MAINTAINER=	flz@FreeBSD.org
COMMENT=	Feed aggregator written in Python using the Django framework

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/feedparser.py:${PORTSDIR}/textproc/py-feedparser \
		django-admin.py:${PORTSDIR}/www/py-django

DIST_SUBDIR=	python
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	Feedjack

PLIST_SUB=	FEEDJACKVER=${PORTVERSION}	\
		PYTHONVER=${PYTHON_VER}

NO_STAGE=	yes
.include <bsd.port.mk>
