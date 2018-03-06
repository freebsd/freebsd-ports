# $FreeBSD$

PORTNAME=	feedjack
PORTVERSION=	0.9.16
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://www.feedjack.org/download/
DISTNAME=	Feedjack-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Feed aggregator written in Python using the Django framework

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/feedparser.py:textproc/py-feedparser@${FLAVOR} \
		django-admin.py:www/py-django18@${FLAVOR}

DIST_SUBDIR=	python
USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
