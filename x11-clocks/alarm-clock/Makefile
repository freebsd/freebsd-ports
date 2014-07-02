# Created by: Romain Tartière <romain@blogreen.org>
# $FreeBSD$

PORTNAME=	alarm-clock
PORTVERSION=	1.4
PORTREVISION=	3
CATEGORIES=	x11-clocks deskutils
MASTER_SITES=	http://www.alarm-clock.pl/media/distfiles/

MAINTAINER=	romain@FreeBSD.org
COMMENT=	Alarm Clock for the GNOME desktop

LICENSE=	GPLv3

LIB_DEPENDS=	libunique-1.0.so:${PORTSDIR}/x11-toolkits/unique \
		libnotify.so:${PORTSDIR}/devel/libnotify

GNU_CONFIGURE=	yes
USES=		gettext pathfix gmake pkgconfig tar:bzip2
USE_GSTREAMER=	yes
USE_GNOME=	gtk20

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
