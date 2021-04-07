PORTNAME=	rmlint
DISTVERSIONPREFIX=	v
DISTVERSION=	2.10.1-11
DISTVERSIONSUFFIX=	-ga726d0cb
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	jockl@pianojockl.org
COMMENT=	Remove duplicates and other lint from your filesystem

LICENSE=	GPLv3

BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx@${PY_FLAVOR}
LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib

USES=		gnome pkgconfig python:build scons
USE_GITHUB=	yes
GH_ACCOUNT=	sahib
USE_GNOME=	glib20

MAKE_ARGS=	--actual-prefix=${PREFIX} \
		--prefix=${STAGEDIR}${PREFIX} \
		--without-gui

PLIST_FILES=	bin/rmlint \
		share/man/man1/rmlint.1.gz

OPTIONS_DEFINE=	NLS

NLS_USES=		gettext-runtime
NLS_CONFIGURE_WITH=	gettext

.include <bsd.port.mk>
