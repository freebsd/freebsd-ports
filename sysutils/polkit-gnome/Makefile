PORTNAME=	polkit-gnome
PORTVERSION=	0.105
PORTREVISION=	5
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME frontend to the PolicyKit framework
WWW=		https://www.freedesktop.org/wiki/Software/polkit/

LICENSE=	LGPL20

LIB_DEPENDS=	libpolkit-gobject-1.so:sysutils/polkit

USES=		gettext gmake gnome pathfix pkgconfig tar:xz
USE_GNOME=	gnomeprefix gtk30 intlhack
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-gtk-doc \
		--localstatedir=/var
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

SUB_FILES=	polkit-gnome.desktop

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/xdg/autostart
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.desktop ${STAGEDIR}${PREFIX}/etc/xdg/autostart/

.include <bsd.port.mk>
