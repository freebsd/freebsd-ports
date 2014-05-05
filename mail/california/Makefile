# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/mail/california/Makefile 19604 2014-05-02 08:32:11Z gusi $

PORTNAME=	california
PORTVERSION=	0.1.0
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Calendar client for GNOME 3

LIB_DEPENDS=	libwebkitgtk-3.0.so:${PORTSDIR}/www/webkit-gtk3 \
		libsoup-2.4.so:${PORTSDIR}/devel/libsoup \
		libgee-0.8.so:${PORTSDIR}/devel/libgee \
		libgdata.so:${PORTSDIR}/devel/libgdata \
		libgoa-1.0.so:${PORTSDIR}/net/gnome-online-accounts

USES=		gettext gmake pathfix pkgconfig tar:xz
USE_GNOME=	evolutiondataserver3 glib20 gnomedocutils gnomeprefix \
		gtk30 intlhack introspection
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--disable-unity
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
		@${REINPLACE_CMD} -e 's|californiadocdir = $${prefix}|californiadocdir = $${prefix}/share|g' \
			${WRKSRC}/Makefile.in

.include <bsd.port.mk>
