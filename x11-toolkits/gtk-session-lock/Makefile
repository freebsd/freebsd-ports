PORTNAME=	gtk-session-lock
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.0
CATEGORIES=	x11-toolkits

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	GTK Session Lock for GTK3
WWW=		https://github.com/Cu3PO42/gtk-session-lock

LICENSE=	GPLv3+ MIT
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3+ =	${WRKSRC}/LICENSE_GPL.txt
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE_MIT.txt

BUILD_DEPENDS=	wayland-protocols>=1.16:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-client.so:graphics/wayland

USES=		compiler:c11 gnome meson pkgconfig vala:build
USE_GNOME=	gtk30 introspection:build
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	Cu3PO42

.include <bsd.port.mk>
