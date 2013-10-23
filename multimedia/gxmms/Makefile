# Created by: Radek Kozlowski <radek@raadradd.com>
# $FreeBSD$

PORTNAME=	gxmms
PORTVERSION=	0.3.0
CATEGORIES=	multimedia gnome
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple GNOME panel applet for controlling XMMS

USE_GNOME=	gnomehack gnomepanel gnomeprefix intlhack libgnomeui
USES=		gettext gmake pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="`pkg-config --libs libgnomeui-2.0`"
CPPFLAGS+=	-I${LOCALBASE}/include `pkg-config --cflags libgnomeui-2.0`
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_SINGLE=			FRONTEND
OPTIONS_SINGLE_FRONTEND=	XMMS BMP
OPTIONS_DEFAULT=		XMMS

XMMS_DESC=	Use xmms as frontend
BMP_DESC=	Use BMP as frontend

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MXMMS}
CONFIGURE_ARGS+=	--with-xmms
BUILD_DEPENDS+=	xmms:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS+=	xmms:${PORTSDIR}/multimedia/xmms
PLIST_SUB+=	XMMS=""
.else
CONFIGURE_ARGS+=--disable-xmms
PLIST_SUB+=	XMMS="@comment "
.endif

.if ${PORT_OPTIONS:MBMP}
CONFIGURE_ARGS+=--with-bmp
BUILD_DEPENDS+=	beep-media-player:${PORTSDIR}/multimedia/beep-media-player
RUN_DEPENDS+=	beep-media-player:${PORTSDIR}/multimedia/beep-media-player
PLIST_SUB+=	BMP=""
.else
CONFIGURE_ARGS+=--disable-bmp
PLIST_SUB+=	BMP="@comment "
.endif

.include <bsd.port.mk>
