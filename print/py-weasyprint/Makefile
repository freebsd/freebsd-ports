PORTNAME=	weasyprint
PORTVERSION=	69.0
CATEGORIES=	print python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Converts HTML/CSS documents to PDF
WWW=		https://weasyprint.org/

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.2<4:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}brotli>=1.2.0:archivers/py-brotli@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycairo>=1.19.1:graphics/py-pycairo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cairocffi>=1.7.1:graphics/py-cairocffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cairosvg>=2.9.0:graphics/py-cairosvg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cffi>=2.1.0:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cssselect2>=0.9.0:textproc/py-cssselect2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fonttools>=4.63.0:print/py-fonttools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tinyhtml5>=2.1.0:textproc/py-tinyhtml5@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydyf>=0.12.1:print/py-pydyf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyphen>=0.9.1:textproc/py-pyphen@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tinycss2>=1.5.1:textproc/py-tinycss2@${PY_FLAVOR}

USES=		gnome python
USE_PYTHON=	autoplist pep517
USE_GNOME=	gdkpixbuf pango

NO_ARCH=	yes

.include <bsd.port.mk>
