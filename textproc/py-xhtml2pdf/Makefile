PORTNAME=	xhtml2pdf
PORTVERSION=	0.2.6
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PDF generator using HTML and CSS

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}arabic-reshaper>=2.1.0:textproc/py-arabic-reshaper@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}html5lib>=1.0.1:www/py-html5lib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=8.1.1:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pypdf3>=1.0.5:print/py-pypdf3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-bidi>=0.4.2:textproc/py-python-bidi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}reportlab>=3.5.53:print/py-reportlab@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}svglib>=1.2.1:converters/py-svglib@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>=1.0:devel/py-nose@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
