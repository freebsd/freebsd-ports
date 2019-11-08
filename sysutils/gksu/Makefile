# Created by: Jesse van den Kieboom <troplosti@orcaweb.cjb.net>
# $FreeBSD$

PORTNAME=	gksu
PORTVERSION=	2.0.2
PORTREVISION=	7
CATEGORIES=	sysutils
MASTER_SITES=	http://people.debian.org/~kov/gksu/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical frontend to su

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgksu2.so:sysutils/libgksu \
		libgnome-keyring.so:security/libgnome-keyring \
		libstartup-notification-1.so:x11/startup-notification

USES=		gettext-tools gmake gnome libtool pathfix pkgconfig
USE_GNOME=	cairo gconf2 gdkpixbuf2 gnomeprefix gtk20 intlhack
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	NAUTILUS
OPTIONS_DEFAULT=NAUTILUS
OPTIONS_SUB=	yes

NAUTILUS_DESC=			Build extension for GNOME file manager
NAUTILUS_CONFIGURE_ENABLE=	nautilus-extension
NAUTILUS_LIB_DEPENDS=		libnautilus-extension.so:x11-fm/nautilus

post-patch:
	@${REINPLACE_CMD} -e 's|glib/gkeyfile.h|glib.h|g' \
		${WRKSRC}/nautilus-gksu/libnautilus-gksu.c

.include <bsd.port.mk>
