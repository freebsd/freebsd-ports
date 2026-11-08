PORTNAME=	rmlint
DISTVERSIONPREFIX=	v
DISTVERSION=	2.11.0
CATEGORIES=	sysutils

MAINTAINER=	jockl@pianojockl.org
COMMENT=	Remove duplicates and other lint from your filesystem
WWW=		https://rmlint.readthedocs.io/en/latest/

LICENSE=	GPLv3

BUILD_DEPENDS=	sphinx-build-${PYTHON_VER}:textproc/py-sphinx@${PY_FLAVOR}
LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib

USES=		gettext-runtime gnome pkgconfig python:build scons
USE_GITHUB=	yes
GH_ACCOUNT=	sahib
USE_GNOME=	glib20

# blkid is only used to map partitions to their whole disk through Linux sysfs,
# which is of no use on FreeBSD: auto-detection would also add an undeclared
# runtime dependency on filesystems/libblkid.
MAKE_ARGS=	--without-blkid \
		--without-gui

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes

NLS_USES=		gettext-tools
NLS_MAKE_ARGS_OFF=	--without-gettext

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/rmlint

.include <bsd.port.mk>
