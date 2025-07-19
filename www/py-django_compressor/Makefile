PORTNAME=	django_compressor
PORTVERSION=	4.5
PORTREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ultima@FreeBSD.org
COMMENT=	Compresses linked and inline JavaScript/CSS into a single cached file
WWW=		https://github.com/jezdez/django_compressor

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}versiontools>=1.8.2:devel/py-versiontools@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django-appconf>=1.0.2:www/py-django-appconf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rcssmin>=1.1.0:archivers/py-rcssmin@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rjsmin>=1.2.0:archivers/py-rjsmin@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

OPTIONS_DEFINE=		BEAUTIFULSOUP LXML HTML5LIB
BEAUTIFULSOUP_DESC=	Enable BeautifulSoupParser
LXML_DESC=		Enable LxmlParser
HTML5LIB_DESC=		Enable Html5LibParser

BEAUTIFULSOUP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4:www/py-beautifulsoup@${PY_FLAVOR}
LXML_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}lxml5>0:devel/py-lxml5@${PY_FLAVOR}
HTML5LIB_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}html5lib>0:www/py-html5lib@${PY_FLAVOR}

.include <bsd.port.mk>
