# New ports collection makefile for:   freetalk
# Date created:        19 June 2009
# Whom:                Oleg Ginzburg  (oleg.ginzburg@nevosoft.ru)
#
# $FreeBSD$
#

PORTNAME=	freetalk
PORTVERSION=	3.2
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	SAVANNAH/freetalk \
		http://itdev.spb.ru/mirror/

MAINTAINER=	oleg.ginzburg@nevosoft.ru
COMMENT=	GNU console based Jabber client

LIB_DEPENDS=	loudmouth-1.0:${PORTSDIR}/net-im/loudmouth
BUILD_DEPENDS=	guile>=1.8.6:${PORTSDIR}/lang/guile
RUN_DEPENDS=	guile>=1.8.6:${PORTSDIR}/lang/guile

USE_GNOME=	pkgconfig glib20
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

MAN1=		freetalk.1
INFO=		freetalk

OPTIONS=	BEEP "Use beep program" off

.if !defined(WITHOUT_NLS)
PLIST_SUB+=     NLS=""
USE_GETTEXT=    yes
CONFIGURE_ARGS= --with-libintl-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=     NLS="@comment "
.endif

.include <bsd.port.options.mk>

.if defined(WITH_BEEP)
RUN_DEPENDS+=	${LOCALBASE}/bin/beep:${PORTSDIR}/audio/beep
.endif

.include <bsd.port.mk>
