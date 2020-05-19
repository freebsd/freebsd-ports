# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	draftjs_exporter
PORTVERSION=	4.0.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library to convert rich text from Draft.js raw ContentState to HTML

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	HTML5LIB LXML
HTML5LIB_DESC=	Use html5lib as backing engine
LXML_DESC=	Use lxml as backing engine

HTML5LIB_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.4.1<5:www/py-beautifulsoup@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}html5lib>=0.999<1.0.2:www/py-html5lib@${PY_FLAVOR}
LXML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=4.2.0<5:devel/py-lxml@${PY_FLAVOR}

.include <bsd.port.mk>
