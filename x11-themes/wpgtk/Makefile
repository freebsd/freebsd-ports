PORTNAME=	wpgtk
DISTVERSION=	6.7.0
PORTREVISION=	1
CATEGORIES=	x11-themes
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Colorscheme, wallpaper and template manager
WWW=		https://deviantfero.github.io/wpgtk

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR} \
		wal:graphics/pywal@${PY_FLAVOR} \
		${PY_SETUPTOOLS}
RUN_DEPENDS=	feh:graphics/feh \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR} \
		wal:graphics/pywal@${PY_FLAVOR} \
		xsettingsd:x11/xsettingsd

USES=		gnome python
USE_GNOME=	gtk30 pygobject3
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
