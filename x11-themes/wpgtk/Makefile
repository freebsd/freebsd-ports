PORTNAME=	wpgtk
DISTVERSION=	6.5.9
PORTREVISION=	1
CATEGORIES=	x11-themes
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Colorscheme, wallpaper and template manager
WWW=		https://deviantfero.github.io/wpgtk

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gobject3>0:devel/py-gobject3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR} \
		wal:graphics/pywal@${PY_FLAVOR}
RUN_DEPENDS=	feh:graphics/feh \
		${PYTHON_PKGNAMEPREFIX}gobject3>0:devel/py-gobject3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR} \
		wal:graphics/pywal@${PY_FLAVOR} \
		xsettingsd:x11/xsettingsd

USES=		gnome python
USE_GNOME=	gtk30
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
