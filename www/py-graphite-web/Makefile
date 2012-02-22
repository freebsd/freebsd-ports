# New ports collection makefile for:	py-graphite-web
# Date created:		2012-02-18
# Whom:			Evan Sarmiento <esarmiento@wayfair.com>
#
# $FreeBSD$
#

PORTNAME=	graphite-web
PORTVERSION=	0.9.9
CATEGORIES=	www python
MASTER_SITES=	http://launchpad.net/graphite/0.9/${PORTVERSION}/+download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bsdports@wayfair.com
COMMENT=	Enterprise scalable realtime graphing platform

RUN_DEPENDS= ${PYTHON_PKGNAMEPREFIX}cairo>=1.8.10:${PORTSDIR}/graphics/py-cairo \
	     ${PYTHON_PKGNAMEPREFIX}django>=1.3.1:${PORTSDIR}/www/py-django \
	     ${PYTHON_PKGNAMEPREFIX}carbon>=0.9.9:${PORTSDIR}/databases/py-carbon
BUILD_DEPENDS=	${RUN_DEPENDS}

USE_PYTHON= 2.6+
USE_PYDISTUTILS= yes
FETCH_ARGS= -pRr

post-patch:
	${MKDIR} ${WRKSRC}/graphite/webapp
	${CP} -r ${WRKSRC}/webapp/content ${WRKSRC}/graphite/webapp

.include <bsd.port.mk>
