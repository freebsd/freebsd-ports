PORTNAME=	PackageKit
PORTVERSION=	1.3.2
PORTREVISION=	1
CATEGORIES=	ports-mgmt sysutils
MASTER_SITES=	https://www.freedesktop.org/software/PackageKit/releases/

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	DBUS packaging abstraction layer
WWW=		https://www.freedesktop.org/software/PackageKit/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl \
		vapigen:lang/vala \
		xsltproc:textproc/libxslt
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libpolkit-gobject-1.so:sysutils/polkit \
		libpkg.so:${PKG_ORIGIN}
RUN_DEPENDS=	console-kit-daemon:sysutils/consolekit2

USES=		cpe gettext gnome meson pkgconfig \
		python shebangfix sqlite:3 tar:xz

USE_GNOME=	gtk30 glib20 intltool introspection
USE_LDCONFIG=	yes

CPE_VENDOR=	packagekit_project
SHEBANG_FILES=	contrib/cron/packagekit-background.cron \
		tests/data/pk-spawn-test-sigquit.py \
		tests/data/pk-spawn-dispatcher.py

MESON_ARGS=	-Dsysconfdir=${PREFIX}/etc \
		-Dpackaging_backend=freebsd -Dsystemd=false -Doffline_update=false \
		-Dbash_completion=false -Dbash_command_not_found=false \
		-Dgstreamer_plugin=false

OPTIONS_DEFINE=	LOCAL_CHECKOUT

LOCAL_CHECKOUT_DESC=		Support running tests (not for production use)
LOCAL_CHECKOUT_TEST_DEPENDS=	bash:shells/bash
LOCAL_CHECKOUT_MESON_TRUE=	local_checkout

post-install:
	${MV} ${STAGEDIR}/var/lib/PackageKit/transactions.db ${STAGEDIR}/var/lib/PackageKit/transactions.db.sample

.include <bsd.port.mk>
