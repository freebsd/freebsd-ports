PORTNAME=	fwupd
DISTVERSION=	2.0.16
PORTREVISION=	4
CATEGORIES=	sysutils

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Update firmware automatically, safely, and reliably

LICENSE=	LGPL21

BROKEN_FreeBSD_13=	requires at least FreeBSD 14

BUILD_DEPENDS=	blkid:filesystems/libblkid \
		flashrom>0:sysutils/flashrom \
		help2man:misc/help2man \
		${LOCALBASE}/libdata/pkgconfig/fwupd-efi.pc:sysutils/fwupd-efi \
		open-sans>0:x11-fonts/open-sans \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygobject>0:devel/py-pygobject@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pangocffi>0:x11-toolkits/py-pangocffi@${PY_FLAVOR} \
		valgrind>0:devel/valgrind
LIB_DEPENDS=	libcbor.so:devel/libcbor \
		libcurl.so:ftp/curl \
		libdrm.so:graphics/libdrm \
		libefiboot.so:devel/efivar \
		libelf.so:devel/libelf \
		libgcab-1.0.so:archivers/gcab \
		libgnutls.so:security/gnutls \
		libgpg-error.so:security/libgpg-error \
		libgpgme.so:security/gpgme \
		libgusb.so:devel/libgusb \
		libjcat.so:textproc/libjcat \
		libjson-glib-1.0.so:devel/json-glib \
		libprotobuf-c.so:devel/protobuf-c \
		libxmlb.so:textproc/libxmlb
RUN_DEPENDS=	blkid:filesystems/libblkid \
		dbus-daemon:devel/dbus \
		flashrom>0:sysutils/flashrom \
		${LOCALBASE}/libdata/pkgconfig/fwupd-efi.pc:sysutils/fwupd-efi \
		valgrind>0:devel/valgrind

USES=		cmake:indirect gettext gnome libarchive meson pkgconfig python readline shebangfix sqlite vala:build
USE_GITHUB=	yes
USE_GNOME=	glib20 introspection:build
USE_LDCONFIG=	yes
WITH_DEBUG=	yes
USE_RC_SUBR=	fwupd

OPTIONS_DEFINE=	DOCS TEST
OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS=	gtkdoc-scan:textproc/gtk-doc \
			${PYTHON_PKGNAMEPREFIX}gi-docgen>0:textproc/py-gi-docgen@${PY_FLAVOR}
DOCS_MESON_ENABLED=	docs
TEST_MESON_TRUE=	tests

SHEBANG_GLOB=	*.py

MESON_ARGS+=	-Dpolkit=disabled \
		-Dsystemd=disabled \
		-Dpassim=disabled \
		-Dumockdev_tests=disabled \
		-Dplugin_modem_manager=disabled \
		-Dpython=${PYTHON_CMD}

.include <bsd.port.options.mk>

# FreeBSD 14.x needs extra libinotify dependency
.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1500000
LIB_DEPENDS+=	libinotify.so:devel/libinotify
EXTRA_PATCHES=	${PATCHDIR}/extrapatch14-meson.build
.endif

.include <bsd.port.mk>
