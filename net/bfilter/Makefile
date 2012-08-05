# New ports collection makefile for:	bfilter
# Date created:				10.05.2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	bfilter
PORTVERSION=	1.1.4
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Smart filtering HTTP proxy

LIB_DEPENDS=	ACE.6:${PORTSDIR}/devel/ace \
		sigc-2.0.0:${PORTSDIR}/devel/libsigc++20

BROKEN=		does not compile

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN8=		bfilter.8
USE_RC_SUBR=	bfilter

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=--enable-debug
.endif

.if defined(WITH_GUI)
LIB_DEPENDS+=	gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24
CONFIGURE_ARGS+=--with-gui
PLIST_SUB+=	GUI=""
.else
PLIST_SUB+=	GUI="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|"pthreads.*pthread-config"|"${PTHREAD_LIBS}"|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|^SUBDIRS|@WITH_GUI_TRUE@SUBDIRS|g' \
		${WRKSRC}/main/gui/gtk/Makefile.in

post-install:
.if defined(WITH_GUI)
	@${MKDIR} ${PREFIX}/share/applications
	@${INSTALL_DATA} ${WRKSRC}/bfilter.desktop \
		${PREFIX}/share/applications/
	@${MKDIR} ${PREFIX}/share/pixmaps
	@${INSTALL_DATA} ${WRKSRC}/bfilter.png \
		${PREFIX}/share/pixmaps/
.endif

.include <bsd.port.mk>
