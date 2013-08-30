# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	artha
PORTVERSION=	1.0.3
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	lichray@gmail.com
COMMENT=	A free cross-platform English thesaurus

LICENSE=	GPLv2

LIB_DEPENDS=	dbus-glib:${PORTSDIR}/devel/dbus-glib \
		WN:${PORTSDIR}/textproc/wordnet

MAN1=		artha.1

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20 intltool
USES=		gmake pkgconfig

CONFIGURE_ARGS=	--enable-static=no --x-includes=${LOCALBASE}/include \
		--x-libraries=${LOCALBASE}/lib
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/WordNet

OPTIONS_DEFINE=	NOTIFY
NOTIFY_DESC=	Popup word definition as notification

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNOTIFY}
LIB_DEPENDS+=	notify:${PORTSDIR}/devel/libnotify
.endif

.include <bsd.port.mk>
