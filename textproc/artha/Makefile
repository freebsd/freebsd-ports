# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	artha
PORTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	lichray@gmail.com
COMMENT=	Free cross-platform English thesaurus

LICENSE=	GPLv2

LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
		libWN.so:textproc/wordnet

GNU_CONFIGURE=	yes
USE_GNOME=	gtk20 intltool
USES=		gmake libtool pkgconfig

CONFIGURE_ARGS=	--enable-static=no --x-includes=${LOCALBASE}/include \
		--x-libraries=${LOCALBASE}/lib
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/WordNet
LIBS+=		`pkg-config --libs gio-2.0`

OPTIONS_DEFINE=	NOTIFY
NOTIFY_DESC=	Popup word definition as notification

NOTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify

.include <bsd.port.mk>
