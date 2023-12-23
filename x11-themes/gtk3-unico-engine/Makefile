PORTNAME=	unico
PORTVERSION=	1.0.2.1
PORTREVISION=	2
CATEGORIES=	x11-themes
MASTER_SITES=	https://distfiles.sigtrap.nl/ \
		LOCAL/nc/mirror
PKGNAMEPREFIX=	gtk3-
PKGNAMESUFFIX=	-engine

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gtk+ 3.0 engine
WWW=		https://launchpad.net/unico

LICENSE=	LGPL3

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
USES=		gmake gnome libtool pkgconfig
USE_GNOME=	cairo glib20 gtk30
USE_LDCONFIG=	yes

.include <bsd.port.mk>
