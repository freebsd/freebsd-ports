# Created by: Meethune Bhowmick <meethune@gmail.com>
# $FreeBSD$

PORTNAME=	libnotify
PORTVERSION=	0.14
PORTREVISION=	14
CATEGORIES=	net-im
MASTER_SITES=	SF/gaim-${PORTNAME}/pidgin-${PORTNAME}/pidgin-${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=	pidgin-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	meethune@gmail.com
COMMENT=	This plugin adds a libnotify interface to Pidgin

BUILD_DEPENDS=	${LOCALBASE}/bin/pidgin:net-im/pidgin \
		${LOCALBASE}/libdata/pkgconfig/libnotify.pc:devel/libnotify
LIB_DEPENDS=	libnotify.so:devel/libnotify \
		libpurple.so:net-im/libpurple

GNU_CONFIGURE=	yes
USES=		gmake gnome libtool pkgconfig
USE_LDCONFIG=	yes
USE_GNOME=	gtk20 intltool

CONFIGURE_ARGS=	--disable-static
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext

.include <bsd.port.mk>
