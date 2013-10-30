# $FreeBSD$

PORTNAME=	gnome-gmail-notifier
PORTVERSION=	0.10.1
PORTREVISION=	3
CATEGORIES=	mail deskutils
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gmail Inbox Monitor for the GNOME2 desktop

LIB_DEPENDS=	notify.4:${PORTSDIR}/devel/libnotify \
		soup-2.4:${PORTSDIR}/devel/libsoup \
		gnome-keyring.0:${PORTSDIR}/security/gnome-keyring

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USES=		gettext gmake pkgconfig
USE_GNOME=	glib20 gtk20 gconf2 libxml2 librsvg2
USE_GSTREAMER=	good
LDFLAGS+=	-L${LOCALBASE}/lib -lintl

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|@DATADIRNAME@|share|' ${WRKSRC}/po/Makefile.in.in
	@${REINPLACE_CMD} -e 's|<glib/gthread.h>|<glib.h>|g' ${WRKSRC}/src/main.h


.include <bsd.port.mk>
