PORTNAME=	fprintd
DISTVERSIONPREFIX=	v
DISTVERSION=	1.94.4
CATEGORIES=	security

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Daemon that provides fingerprint scanning functionality over D-Bus
WWW=		https://www.freedesktop.org/wiki/Software/fprint/fprintd/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libbasu.so:devel/basu \
		libfprint-2.so:security/libfprint \
		libpolkit-gobject-1.so:sysutils/polkit

USES=		gettext gnome meson pkgconfig
USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	libfprint
USE_GNOME=	glib20 intltool

MESON_ARGS=	-Dlibsystemd=basu \
		-Dsystemd=false

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
