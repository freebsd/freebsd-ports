# New ports collection makefile for:	py-django_compressor
# Date created:		2011-07-21
# Whom:			Lung-Pin Chang <changlp@cs.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	django_compressor
PORTVERSION=	0.9.2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	changlp@cs.nctu.edu.tw
COMMENT=	Compresses linked and inline javascript/CSS into a single cached file

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

OPTIONS=	BEAUTIFULSOUP "Enable BeautifulSoupParser" Off \
		LXML "Enable LxmlParser" Off \
		HTML5LIB "Enable Html5LibParser" Off

.include <bsd.port.options.mk>

.if defined(WITH_BEAUTIFULSOUP)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>0:${PORTSDIR}/www/py-beautifulsoup
.endif

.if defined(WITH_LXML)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}lxml>0:${PORTSDIR}/devel/py-lxml
.endif

.if defined(WITH_HTML5LIB)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}html5lib>0:${PORTSDIR}/www/py-html5lib
.endif

.include <bsd.port.mk>
