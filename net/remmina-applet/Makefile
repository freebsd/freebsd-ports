# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	remmina
PORTVERSION=	0.8.1
PORTREVISION=	1
CATEGORIES=	net gnome
MASTER_SITES=	SF/${PORTNAME}/0.8
PKGNAMESUFFIX=	-applet
DISTNAME=	${PORTNAME}-gnome-${PORTVERSION}

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	A GNOME Desktop applet for Remmina

RUN_DEPENDS=	remmina:${PORTSDIR}/net/remmina

OPTIONS_DEFINE=	AVAHI

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack glib20 gtk20 gnomepanel
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MAVAHI}
LIB_DEPENDS+=	avahi-ui.0:${PORTSDIR}/net/avahi-gtk
.else
CONFIGURE_ARGS+=--disable-avahi
.endif

.include <bsd.port.mk>
