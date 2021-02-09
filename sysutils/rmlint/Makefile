# $FreeBSD$

PORTNAME=	rmlint
DISTVERSIONPREFIX=	v
DISTVERSION=	2.10.1
CATEGORIES=	sysutils

MAINTAINER=	jockl@pianojockl.org
COMMENT=	Remove duplicates and other lint from your filesystem

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/lib/libglib-2.0.so:devel/glib20 \
		gettext:devel/gettext \
		pkgconf:devel/pkgconf \
		sphinx-build:textproc/py-sphinx@${PY_FLAVOR}
LIB_DEPENDS=	libelf.so:devel/libelf \
		libjson-glib-1.0.so:devel/json-glib

USES=		gnome python scons
USE_GITHUB=	yes
GH_ACCOUNT=	sahib
GH_PROJECT=	rmlint
GH_TAGNAME=	a726d0cbf839d7a0f35962d67e0f60054d0364f6
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
