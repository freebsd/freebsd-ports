# Created by: Radek Kozlowski <radek@raadradd.com>
# $FreeBSD$

PORTNAME=	gxmms
PORTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	multimedia gnome
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple GNOME panel applet for controlling XMMS

DEPRECATED=	Abandonware, please consider using multimedia/audacious instead
EXPIRATION_DATE=	2014-03-23

USE_GNOME=	gnomepanel gnomeprefix intlhack libgnomeui
USES=		gettext gmake pkgconfig pathfix
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="`pkg-config --libs libgnomeui-2.0`"
CPPFLAGS+=	-I${LOCALBASE}/include `pkg-config --cflags libgnomeui-2.0`
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_SINGLE=			FRONTEND
OPTIONS_DEFAULT=		XMMS
OPTIONS_SINGLE_FRONTEND=	XMMS

XMMS_DESC=	Use xmms as frontend

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

CONFIGURE_ARGS+=--disable-bmp

.include <bsd.port.mk>
