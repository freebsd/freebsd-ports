# Created by: Oleg Ginzburg  (olevole@olevole.ru)
# $FreeBSD$

PORTNAME=	freetalk
PORTVERSION=	3.2
PORTREVISION=	2
CATEGORIES=	net-im
MASTER_SITES=	SAVANNAH/freetalk \
		http://itdev.spb.ru/mirror/

MAINTAINER=	olevole@olevole.ru
COMMENT=	GNU console based Jabber client

OPTIONS_DEFINE=	NLS

LIB_DEPENDS=	libloudmouth-1.so:${PORTSDIR}/net-im/loudmouth
BUILD_DEPENDS=	guile>=1.8.6:${PORTSDIR}/lang/guile
RUN_DEPENDS=	guile>=1.8.6:${PORTSDIR}/lang/guile

USES=		pkgconfig
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_WITH=libintl-prefix=${LOCALBASE}
NLS_CONFIGURE_OFF= --disable-nls

.include <bsd.port.mk>
