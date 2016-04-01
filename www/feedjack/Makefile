# $FreeBSD$

PORTNAME=	feedjack
PORTVERSION=	0.9.16
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://www.feedjack.org/download/
DISTNAME=	Feedjack-${PORTVERSION}

MAINTAINER=	flz@FreeBSD.org
COMMENT=	Feed aggregator written in Python using the Django framework

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/feedparser.py:textproc/py-feedparser \
		django-admin.py:www/py-django18

DIST_SUBDIR=	python
USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
