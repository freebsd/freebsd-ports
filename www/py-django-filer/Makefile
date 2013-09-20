# Created by: Matthew X. Economou <xenophon+fbsdports@irtnog.org>
# $FreeBSD$

PORTNAME=	django-filer
PORTVERSION=	0.8.6
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	xenophon+fbsdports@irtnog.org
COMMENT=	File and Image Management Application for django

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django>=0:${PORTSDIR}/www/py-django \
		${PYTHON_PKGNAMEPREFIX}django-easy-thumbnails>=0:${PORTSDIR}/graphics/py-django-easy-thumbnails \
		${PYTHON_PKGNAMEPREFIX}imaging>=0:${PORTSDIR}/graphics/py-imaging

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

NO_STAGE=	yes
post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
