# New ports collection makefile for:	alarm-clock
# Date created:		2008-06-16
# Whom:			Romain Tartière <romain@blogreen.org>
#
# $FreeBSD$
#

PORTNAME=	alarm-clock
PORTVERSION=	1.4
CATEGORIES=	x11-clocks deskutils
MASTER_SITES=	http://www.alarm-clock.pl/media/distfiles/

MAINTAINER=	romain@FreeBSD.org
COMMENT=	Alarm Clock for the GNOME desktop

LIB_DEPENDS=	unique-1:${PORTSDIR}/x11-toolkits/unique \
		notify.1:${PORTSDIR}/devel/libnotify

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GSTREAMER=	yes
USE_GNOME=	gnomehack gtk20

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
