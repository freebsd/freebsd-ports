# New ports collection makefile for:	gnome-gmail-notifier
# Date created:				Nov 16 2007
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnome-gmail-notifier
PORTVERSION=	0.9.4
PORTREVISION=	4
CATEGORIES=	mail deskutils
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	avl@FreeBSD.org
COMMENT=	A Gmail Inbox Monitor for the GNOME2 desktop

LIB_PC_DEPENDS=	libnotify:devel/libnotify	\
		libsoup-2.4:devel/libsoup	\
		gnome-keyring-1:security/gnome-keyring

BUILD_DEPENDS=	${LIB_PC_DEPENDS:C|^|${LOCALBASE}/libdata/pkgconfig/|:C|:|.pc:${PORTSDIR}/|}
RUN_DEPENDS=	${LIB_PC_DEPENDS:C|^|${LOCALBASE}/libdata/pkgconfig/|:C|:|.pc:${PORTSDIR}/|}

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20 gtk20 libgnome libgnomeui libxml2 libglade2
USE_GSTREAMER=	good

post-patch:
	@${REINPLACE_CMD} -e 's|@DATADIRNAME@|share|' ${WRKSRC}/po/Makefile.in.in

.include <bsd.port.mk>
