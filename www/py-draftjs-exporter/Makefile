PORTNAME=	draftjs-exporter
PORTVERSION=	5.1.0
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	draftjs_exporter-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library to convert rich text from Draft.js raw ContentState to HTML
WWW=		https://github.com/springload/draftjs_exporter

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python:3.9+
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	HTML5LIB LXML
HTML5LIB_DESC=	Use html5lib as backing engine
LXML_DESC=	Use lxml as backing engine

HTML5LIB_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.4.1<5:www/py-beautifulsoup@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}html5lib>=0.999<2:www/py-html5lib@${PY_FLAVOR}
LXML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml5>=4.2.0<6:devel/py-lxml5@${PY_FLAVOR}

.include <bsd.port.mk>
