PORTNAME=	usbredir
DISTVERSION=	0.13.0
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	net devel

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Protocol for redirection of USB traffic
WWW=		https://gitlab.freedesktop.org/spice/usbredir/

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	dual

USES=		gnome libtool meson pkgconfig
USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	spice
USE_GNOME=	glib20
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
