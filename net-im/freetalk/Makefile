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

OPTIONS_DEFINE=	BEEP NLS
BEEP_DESC=	Use beep program

LIB_DEPENDS=	loudmouth-1.0:${PORTSDIR}/net-im/loudmouth
BUILD_DEPENDS=	guile>=1.8.6:${PORTSDIR}/lang/guile
RUN_DEPENDS=	guile>=1.8.6:${PORTSDIR}/lang/guile

USES=		pkgconfig
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

MAN1=		freetalk.1
INFO=		freetalk

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
PLIST_SUB+=     NLS=""
USES+=		gettext
CONFIGURE_ARGS= --with-libintl-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=     NLS="@comment "
.endif

.if ${PORT_OPTIONS:MBEEP}
RUN_DEPENDS+=	${LOCALBASE}/bin/beep:${PORTSDIR}/audio/beep
.endif

.include <bsd.port.mk>
