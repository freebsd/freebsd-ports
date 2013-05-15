# Created by: Norikatsu Shigemura <nork@FreeBSD.org>
# $FreeBSD$

PORTNAME=	g2ipmsg
PORTVERSION=	0.9.6
CATEGORIES=	net gnome
MASTER_SITES=	http://ipmsg.org/archive/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Popup style message communication tool for GNOME2

LICENSE=	GPLv2 # (or later)

OPTIONS_DEFINE=	GNOMEPANEL
OPTIONS_DEFAULT=	GNOMEPANEL
GNOMEPANEL_DESC=	GNOME Panel Applet

USES=		gettext pathfix pkgconfig
USE_GNOME=	desktopfileutils gnomeprefix libgnomeui
USE_GSTREAMER=	vorbis
USE_OPENSSL=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-doxygen-doc \
		--enable-systray \
		--with-ssl=${OPENSSLBASE}
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	g2ipmsg.schemas

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNOMEPANEL}
USE_GNOME+=	gnomepanel
PLIST_SUB+=	GNOMEPANEL=""
.else
CONFIGURE_ARGS+=--disable-applet
PLIST_SUB+=	GNOMEPANEL="@comment "
.endif

post-install:
	@update-desktop-database

.include <bsd.port.mk>
