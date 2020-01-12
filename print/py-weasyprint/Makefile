# Created by: D'Arcy Cain <darcy@druid.net>
# $FreeBSD$

PORTNAME=	weasyprint
PORTVERSION=	51
CATEGORIES=	print python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	WeasyPrint-${PORTVERSION}

MAINTAINER=	darcy@druid.net
COMMENT=	Converts HTML/CSS documents to PDF

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-runner>=0.1:devel/py-pytest-runner@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cairo>=1.15.4:graphics/py-cairo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cairocffi>=0.9.0:graphics/py-cairocffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cairosvg>=2.4.0:graphics/py-cairosvg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cffi>=0.6:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cssselect2>=0.1:textproc/py-cssselect2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}html5lib>=0.999999999:www/py-html5lib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyphen>=0.9.1:textproc/py-pyphen@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tinycss2>=1.0.0:textproc/py-tinycss2@${PY_FLAVOR}

USES=		gnome python:3.6+
USE_PYTHON=	distutils autoplist
USE_GNOME=	gdkpixbuf2 pango

NO_ARCH=	yes

.include <bsd.port.mk>
