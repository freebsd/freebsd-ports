# New ports collection makefile for:	py-graphite-web
# Date created:		2012-02-18
# Whom:			Evan Sarmiento <esarmiento@wayfair.com>
#
# $FreeBSD$
#

PORTNAME=	graphite-web
PORTVERSION=	0.9.10
PORTREVISION=	1
CATEGORIES=	www python
#MASTER_SITES=	CHEESESHOP \
MASTER_SITES=	https://github.com/downloads/graphite-project/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bsdports@wayfair.com
COMMENT=	Enterprise scalable realtime graphing platform

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cairo>=1.8.10:${PORTSDIR}/graphics/py-cairo \
		${PYTHON_PKGNAMEPREFIX}carbon>=${PORTVERSION}:${PORTSDIR}/databases/py-carbon \
		${PYTHON_PKGNAMEPREFIX}django>=1.3.1:${PORTSDIR}/www/py-django \
		${PYTHON_PKGNAMEPREFIX}django-tagging>=0.3.1:${PORTSDIR}/www/py-django-tagging

FETCH_ARGS=	-pRr
USE_PYTHON=	-2.7
USE_PYDISTUTILS=yes

post-patch:
	@${MKDIR} ${WRKSRC}/graphite/webapp/
	@${CP} -LR ${WRKSRC}/webapp/content ${WRKSRC}/graphite/webapp

.include <bsd.port.mk>
