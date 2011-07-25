# New ports collection makefile for:	artha
# Date created:		2011-03-15
# Whom:			Zhihao Yuan <lichray@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	artha
PORTVERSION=	1.0.2
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	lichray@gmail.com
COMMENT=	A free cross-platform English thesaurus

LICENSE=	GPLv2

LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		WN.2:${PORTSDIR}/textproc/wordnet

MAN1=		artha.1

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20 intltool pkgconfig

CONFIGURE_ARGS=	--enable-static=no --x-includes=${LOCALBASE}/include \
		--x-libraries=${LOCALBASE}/lib
CONFIGURE_ENV=	LDFLAGS=-L${LOCALBASE}/lib
CPPFLAGS=	-I${LOCALBASE}/include -I${LOCALBASE}/include/WordNet

OPTIONS=	NOTIFY "Popup word definition as notification" On

.include <bsd.port.options.mk>

.if defined(WITH_NOTIFY)
LIB_DEPENDS+=	notify.1:${PORTSDIR}/devel/libnotify
.endif

.include <bsd.port.mk>
