# Created by: Lung-Pin Chang <changlp@cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	django_compressor
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	changlp@cs.nctu.edu.tw
COMMENT=	Compresses linked and inline JavaScript/CSS into a single cached file

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}versiontools>=1.8.2:devel/py-versiontools
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django-appconf>=0.4:www/py-django-appconf \
		${PYTHON_PKGNAMEPREFIX}rcssmin>=0:archivers/py-rcssmin \
		${PYTHON_PKGNAMEPREFIX}rjsmin>=0:archivers/py-rjsmin

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

OPTIONS_DEFINE=		BEAUTIFULSOUP LXML HTML5LIB SLIMIT
BEAUTIFULSOUP_DESC=	Enable BeautifulSoupParser
LXML_DESC=		Enable LxmlParser
HTML5LIB_DESC=		Enable Html5LibParser
SLIMIT_DESC=		Enable SlimIt JavaScript filter

BEAUTIFULSOUP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4:www/py-beautifulsoup
LXML_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml
HTML5LIB_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}html5lib>0:www/py-html5lib
SLIMIT_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}slimit>=0.8.1:www/py-slimit

.include <bsd.port.mk>
