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

OPTIONS_DEFINE=	BEAUTIFULSOUP LXML HTML5LIB
BEAUTIFULSOUP_DESC=	Enable BeautifulSoupParser
LXML_DESC=		Enable LxmlParser
HTML5LIB_DESC=		Enable Html5LibParser

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBEAUTIFULSOUP}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/BeautifulSoup.py:${PORTSDIR}/www/py-beautifulsoup32
.endif

.if ${PORT_OPTIONS:MLXML}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}lxml>0:${PORTSDIR}/devel/py-lxml
.endif

.if ${PORT_OPTIONS:MHTML5LIB}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}html5lib>0:${PORTSDIR}/www/py-html5lib
.endif

.include <bsd.port.mk>
