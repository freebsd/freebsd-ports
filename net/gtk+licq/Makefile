# New ports collection makefile for:    gtk+licq
# Date created:                         17 Oct 2000
# Whom:                                 Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	gtk+licq
PORTVERSION=	0.50.1
CATEGORIES=	net
MASTER_SITES=	http://gtk.licq.org/download/

MAINTAINER=	ishmael27@home.com

BUILD_DEPENDS=	${LOCALBASE}/include/licq/licq_icqd.h:${PORTSDIR}/net/licq
RUN_DEPENDS=	licq:${PORTSDIR}/net/licq

USE_GMAKE=	yes
USE_GTK=	yes
WANT_GNOME=	yes
USE_LIBTOOL=	yes
USE_AUTOMAKE=	yes

.if defined(WITHOUT_GNOME)
CONFIGURE_ARGS=	--disable-gnome
GUITYPE=	gtk
.else
GUITYPE=	gnome
.endif

PLIST_SUB=	GUITYPE=${GUITYPE}

CONFIGURE_ENV=	CPPFLAGS=-"I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

post-install:
	strip ${PREFIX}/lib/licq/licq_${GUITYPE}_gui.a

.include <bsd.port.mk>
