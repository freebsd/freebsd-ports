# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom$

PORTNAME=	telepathy-farsight
PORTVERSION=	0.0.19
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/${PORTNAME}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Farsight Connection Manager for Telepathy Framework

LIB_DEPENDS=	dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		telepathy-glib:${PORTSDIR}/net-im/telepathy-glib \
		gstfarsight-0.10:${PORTSDIR}/net-im/farsight2

GNU_CONFIGURE=	yes
USES=		gmake pkgconfig
USE_LDCONFIG=	yes
USE_PYTHON=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomehack glib20 ltverhack libxslt:build
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

NO_STAGE=	yes
.include <bsd.port.mk>
