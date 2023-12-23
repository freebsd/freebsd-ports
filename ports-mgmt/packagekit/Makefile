PORTNAME=	PackageKit
PORTVERSION=	1.2.6
PORTREVISION=	3
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
		libpolkit-gobject-1.so:sysutils/polkit
RUN_DEPENDS=	console-kit-daemon:sysutils/consolekit2

USES=		cpe desktop-file-utils gettext gnome meson pkgconfig \
		python shared-mime-info shebangfix sqlite:3 tar:xz

USE_GNOME=	gtk30 glib20 intltool introspection
USE_LDCONFIG=	yes

CPE_VENDOR=	packagekit_project
SHEBANG_FILES=	contrib/cron/packagekit-background.cron

MESON_ARGS=	-Dlocalstatedir=/var -Dsysconfdir=${PREFIX}/etc \
		-Dsystemd=false -Doffline_update=false \
		-Dbash_completion=false -Dbash_command_not_found=false \
		-Dgstreamer_plugin=false

.include <bsd.port.mk>
