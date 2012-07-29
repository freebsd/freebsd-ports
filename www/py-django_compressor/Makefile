# New ports collection makefile for:	py-django_compressor
# Date created:		2011-07-21
# Whom:			Lung-Pin Chang <changlp@cs.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	django_compressor
PORTVERSION=	1.1.2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	changlp@cs.nctu.edu.tw
COMMENT=	Compresses linked and inline JavaScript/CSS into a single cached file

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}versiontools>=1.8.2:${PORTSDIR}/devel/py-versiontools
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django-appconf>=0.4:${PORTSDIR}/www/py-django-appconf

USE_PYTHON=	-2.7
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
