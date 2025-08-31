PORTNAME=	weasyprint
PORTVERSION=	61.2
PORTREVISION=	1
CATEGORIES=	print python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Converts HTML/CSS documents to PDF
WWW=		https://weasyprint.org/

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.2<4:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}brotli>=1.0.9:archivers/py-brotli@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cairo>=1.15.4:graphics/py-cairo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cairocffi>=0.9.0:graphics/py-cairocffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cairosvg>=2.4.0:graphics/py-cairosvg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cffi>=0.6:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cssselect2>=0.1:textproc/py-cssselect2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fonttools>=4.38:print/py-fonttools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}html5lib>=0.999999999:www/py-html5lib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydyf>=0.5.0:print/py-pydyf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyphen>=0.9.1:textproc/py-pyphen@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tinycss2>=1.0.0:textproc/py-tinycss2@${PY_FLAVOR}

USES=		gnome python
USE_PYTHON=	autoplist pep517
USE_GNOME=	gdkpixbuf pango

NO_ARCH=	yes

.include <bsd.port.mk>
