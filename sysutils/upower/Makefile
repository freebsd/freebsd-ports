PORTNAME=	upower
DISTVERSIONPREFIX=	v
DISTVERSION=	1.90.10
CATEGORIES=	sysutils

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	D-Bus daemon for simplifying power management tasks
WWW=		https://upower.freedesktop.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpolkit-gobject-1.so:sysutils/polkit

USES=		compiler:c11 gettext-tools gnome localbase meson pkgconfig
USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org/
USE_GNOME=	glib20 introspection:build
USE_LDCONFIG=	yes
MESON_ARGS=	-Dgtk-doc=false \
		-Didevice=disabled \
		-Dos_backend=freebsd \
		-Dpolkit=enabled \
		-Dsystemdsystemunitdir=no \
		-Dudevhwdbdir=no \
		-Dudevrulesdir=no \
		-Dzshcompletiondir=no
LDFLAGS+=	-lkvm

OPTIONS_DEFINE=		MANPAGES NLS
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=		yes

MANPAGES_BUILD_DEPENDS=	${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl \
			docbook-sgml>0:textproc/docbook-sgml \
			docbook-xml>0:textproc/docbook-xml
MANPAGES_USE=		GNOME=libxslt:build
MANPAGES_MESON_TRUE=	man

NLS_USES=	gettext-runtime

post-patch-NLS-off:
	@${REINPLACE_CMD} -e "/^subdir('po')/d" ${WRKSRC}/meson.build

.include <bsd.port.mk>
