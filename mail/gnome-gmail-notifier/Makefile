# $FreeBSD$

PORTNAME=	gnome-gmail-notifier
PORTVERSION=	0.10.1
PORTREVISION=	6
CATEGORIES=	mail deskutils
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gmail Inbox Monitor for the GNOME2 desktop

BROKEN=		Unfetchable (google code has gone away)

LIB_DEPENDS=	libnotify.so:devel/libnotify \
		libsoup-2.4.so:devel/libsoup \
		libgnome-keyring.so:security/libgnome-keyring

GNU_CONFIGURE=	yes
USES=		gettext gmake pkgconfig tar:bzip2
USE_GNOME=	glib20 gtk20 gconf2 intltool libxml2 librsvg2
USE_GSTREAMER=	good
LDFLAGS+=	-L${LOCALBASE}/lib -lintl

post-patch:
	@${REINPLACE_CMD} -e 's|@DATADIRNAME@|share|' ${WRKSRC}/po/Makefile.in.in
	@${REINPLACE_CMD} -e 's|<glib/gthread.h>|<glib.h>|g' ${WRKSRC}/src/main.h

.include <bsd.port.mk>
