PORTNAME=	PackageKit
PORTVERSION=	1.4.0
CATEGORIES=	ports-mgmt sysutils
MASTER_SITES=	https://www.freedesktop.org/software/PackageKit/releases/

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	DBUS packaging abstraction layer
WWW=		https://www.freedesktop.org/software/PackageKit/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	docbook-xsl>=0:textproc/docbook-xsl \
		docbook-xsl-ns>=0:textproc/docbook-xsl-ns \
		vapigen:lang/vala \
		xsltproc:textproc/libxslt
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libjansson.so:devel/jansson \
		libpolkit-gobject-1.so:sysutils/polkit \
		libpkg.so:${PKG_ORIGIN}
RUN_DEPENDS=	console-kit-daemon:sysutils/consolekit2
TEST_DEPENDS=	bash:shells/bash

USES=		cpe dbus-testing gettext gnome meson pkgconfig \
		python shebangfix sqlite:3 tar:xz

USE_GNOME=	gtk30 glib20 intltool introspection
USE_LDCONFIG=	yes

CPE_VENDOR=	packagekit_project
SHEBANG_FILES=	contrib/cron/packagekit-background.cron \
		tests/data/*.py \
		tests/runner/*.py

MESON_ARGS=	-Dsysconfdir=${PREFIX}/etc \
		-Dpackaging_backend=freebsd -Dsystemd=false -Doffline_update=false \
		-Dbash_completion=false -Dbash_command_not_found=false \
		-Dgstreamer_plugin=false

post-patch:
# allow tests to run
	${REINPLACE_CMD} -e 's|/usr/share/|${LOCALBASE}/share|g' \
		${WRKSRC}/tests/runner/run-daemon-test.py

post-install:
	${MV} ${STAGEDIR}/var/lib/PackageKit/transactions.db ${STAGEDIR}/var/lib/PackageKit/transactions.db.sample

.include <bsd.port.mk>
