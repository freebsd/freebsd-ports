# Created by: Oleg Ginzburg  (olevole@olevole.ru)
# $FreeBSD$

PORTNAME=	freetalk
PORTVERSION=	3.2
PORTREVISION=	5
CATEGORIES=	net-im
MASTER_SITES=	SAVANNAH/freetalk \
		http://itdev.spb.ru/mirror/

MAINTAINER=	olevole@olevole.ru
COMMENT=	GNU console based Jabber client

OPTIONS_DEFINE=	NLS

LIB_DEPENDS=	libloudmouth-1.so:net-im/loudmouth
BUILD_DEPENDS=	guile>=1.8.6:lang/guile
RUN_DEPENDS=	guile>=1.8.6:lang/guile

USES=		pkgconfig
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-lpthread -L${LOCALBASE}/lib
INFO=		freetalk

OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_WITH=libintl-prefix=${LOCALBASE}
NLS_CONFIGURE_OFF= --disable-nls

.include <bsd.port.mk>
