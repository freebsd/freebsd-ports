# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	linphone
PORTVERSION=	3.2.1
PORTREVISION?=	2
PORTEPOCH=	1
CATEGORIES?=	net
MASTER_SITES=	SAVANNAH/${PORTNAME}/3.2.x/sources

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Web phone that supports SIP protocol

LIB_DEPENDS=	libgsm.so:${PORTSDIR}/audio/gsm \
		libspeex.so:${PORTSDIR}/audio/speex \
		libeXosip2.so:${PORTSDIR}/net/libexosip2

CONFLICTS=	ortp-[0-9]*

USE_GNOME=	glib20 intlhack
USES=		gmake pathfix pkgconfig
USE_AUTOTOOLS=	libtool
LIBTOOLFILES=	configure oRTP/configure mediastreamer2/configure
CONFIGURE_ARGS=	--disable-ipv6 --disable-manual --disable-ewarning \
		--disable-strict --disable-video --disable-external-ortp \
		--with-osip=${LOCALBASE} --with-gsm=${LOCALBASE}
MAKE_ENV=	SUBDIRS="${SUBDIRS}"
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if defined(LINPHONE_GUI)
BUILD_DEPENDS+=	linphone-base>=${PORTVERSION}:${PORTSDIR}/net/linphone-base
RUN_DEPENDS+=	linphone-base>=${PORTVERSION}:${PORTSDIR}/net/linphone-base
DESCR=		${PKGDIR}/pkg-descr.gui
PLIST=		${PKGDIR}/pkg-plist.gui
USE_GNOME+=	libglade2
MAN1=		linphone.1
SUBDIRS=	pixmaps gtk-glade
.else
PKGNAMESUFFIX=	-base
CONFIGURE_ARGS+=	--enable-gtk_ui=no
MAN1=		linphonec.1 linphonecsh.1 sipomatic.1
SUBDIRS=	po oRTP mediastreamer2 coreapi console
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not compile on powerpc
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|sounds/linphone|linphone/sounds|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s| =| ?=|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/^imgdir =/s|(datadir)|(pkgdatadir)|g' \
		${WRKSRC}/mediastreamer2/src/Makefile.in
	@${REINPLACE_CMD} -e 's|gsm/gsm\.h|gsm.h|g ; \
		 s| -O2 -g ||g' ${WRKSRC}/mediastreamer2/configure
	@${REINPLACE_CMD} -e 's|gsm/gsm\.h|gsm.h|g' \
		${WRKSRC}/mediastreamer2/src/gsm.c

post-install:
.if defined(LINPHONE_GUI)
	@${LN} -sf linphone-3 ${PREFIX}/bin/linphone
	${INSTALL_MAN} ${WRKSRC}/share/C/linphone.1 ${MANPREFIX}/man/man1
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/share/linphone.desktop \
		${PREFIX}/share/applications
.else
	${INSTALL_MAN} ${WRKSRC}/share/C/linphonec.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/share/C/linphonecsh.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/share/C/sipomatic.1 ${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/share/linphone.pc ${PREFIX}/libdata/pkgconfig
	@${MKDIR} ${DATADIR}/sounds
	${INSTALL_DATA} ${WRKSRC}/share/*.wav ${DATADIR}/sounds
	@${MKDIR} ${DATADIR}/sounds/rings
	${INSTALL_DATA} ${WRKSRC}/share/rings/*.wav ${DATADIR}/sounds/rings
.endif

.include <bsd.port.post.mk>
