# Created by: Romain Tartière <romain@blogreen.org>
# $FreeBSD$

PORTNAME=	alarm-clock
PORTVERSION=	1.4
PORTREVISION=	2
CATEGORIES=	x11-clocks deskutils
MASTER_SITES=	http://www.alarm-clock.pl/media/distfiles/

MAINTAINER=	romain@FreeBSD.org
COMMENT=	Alarm Clock for the GNOME desktop

LIB_DEPENDS=	unique-1:${PORTSDIR}/x11-toolkits/unique \
		notify.4:${PORTSDIR}/devel/libnotify

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USES=		gettext pathfix gmake pkgconfig
USE_GSTREAMER=	yes
USE_GNOME=	gtk20

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
