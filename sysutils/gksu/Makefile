# Created by: Jesse van den Kieboom <troplosti@orcaweb.cjb.net>
# $FreeBSD$

PORTNAME=	gksu
PORTVERSION=	2.0.2
PORTREVISION=	6
CATEGORIES=	sysutils
MASTER_SITES=	http://people.debian.org/~kov/gksu/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical frontend to su

LIB_DEPENDS=	libgksu2.so:sysutils/libgksu \
		libnautilus-extension.so:x11-fm/nautilus \
		libgnome-keyring.so:security/libgnome-keyring

USES=		gettext-tools gmake libtool pathfix pkgconfig
USE_GNOME=	gconf2 gnomeprefix gtk20 intlhack
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -e 's|glib/gkeyfile.h|glib.h|g' \
		${WRKSRC}/nautilus-gksu/libnautilus-gksu.c

.include <bsd.port.mk>
