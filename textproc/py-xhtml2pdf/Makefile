PORTNAME=	xhtml2pdf
PORTVERSION=	0.2.17
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PDF generator using HTML and CSS
WWW=		https://xhtml2pdf.readthedocs.io/en/latest/ \
		https://github.com/xhtml2pdf/xhtml2pdf

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}arabic-reshaper>=3.0.0:textproc/py-arabic-reshaper@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}html5lib>=1.1:www/py-html5lib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=8.1.1:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyhanko>=0.12.1:security/py-pyhanko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyhanko-certvalidator>=0.19.5:security/py-pyhanko-certvalidator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pypdf>=3.1.0:print/py-pypdf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-bidi>=0.4.2:textproc/py-python-bidi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}reportlab>=4.0.4<5:print/py-reportlab@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}svglib>=1.2.1:converters/py-svglib@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>=1.0:devel/py-nose@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
