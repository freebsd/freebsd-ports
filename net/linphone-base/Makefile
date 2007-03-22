# New ports collection makefile for:	linphone
# Date created:				30 December 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	linphone
PORTVERSION=	1.6.0
PORTEPOCH=	1
CATEGORIES?=	net
MASTER_SITES=	${MASTER_SITE_SAVANNAH:S/$/:linphone/} \
		${MASTER_SITE_GNU:S/$/:libosip2/}
MASTER_SITE_SUBDIR=	${PORTNAME}/stable/sources/:linphone \
			osip/:libosip2
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:linphone \
		libosip2-2.2.2${EXTRACT_SUFX}:libosip2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A web phone that supports SIP protocol

LIB_DEPENDS=	jack.0:${PORTSDIR}/audio/jack \
		samplerate.1:${PORTSDIR}/audio/libsamplerate \
		speex.1:${PORTSDIR}/audio/speex \
		osip2.3:${PORTSDIR}/net/libosip2

USE_GNOME=	glib20 gnomehack gnometarget intlhack pkgconfig
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
LIBTOOLFILES=	configure mediastreamer2/configure oRTP/configure
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		PKG_CONFIG="${LOCALBASE}/bin/pkg-config"
CONFIGURE_ARGS=	--disable-ipv6 --disable-gtk-doc --disable-ewarning \
		--without-ilbc --disable-strict --disable-video \
		--with-osip=${LOCALBASE}
MAKE_ENV=	SUBDIRS="${SUBDIRS}"
USE_LDCONFIG=	yes

CFLAGS+=	-DPACKAGE_LOCALE_DIR='\"${PREFIX}/share/locale\"' \
		-DPACKAGE_DATA_DIR='\"${PREFIX}/${DATA_PATH}\"' \
		-DPACKAGE_SOUND_DIR='\"${DATADIR}/sounds\"' \
		-DHAVE_STRUCT_TIMEVAL
CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600000
LIB_DEPENDS+=	readline.[5-9]:${PORTSDIR}/devel/readline
.endif

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
LDFLAGS+=	-lintl
.endif

.if defined(LINPHONE_GUI)
LIB_DEPENDS+=	linphone.7:${PORTSDIR}/net/linphone-base
DESCR=		${PKGDIR}/pkg-descr.gui
PLIST=		${PKGDIR}/pkg-plist.gui
USE_GNOME+=	gnomepanel gnomeprefix
MAN1=		linphone.1
DATA_PATH=	share/gnome
SUBDIRS=	pixmaps gnome
.else
PKGNAMESUFFIX=	-base
CONFIGURE_ARGS+=	--enable-gnome_ui=no
MAN1=		linphonec.1 sipomatic.1
DATA_PATH=	share
SUBDIRS=	po oRTP gsmlib mediastreamer2 media_api exosip coreapi console
.endif

post-extract:
	@${LN} -sf ${WRKDIR}/libosip2-2.2.2/src/osip2/osip_negotiation.c \
		${WRKSRC}/exosip
	@${LN} -sf ${WRKDIR}/libosip2-2.2.2/include/osip2 \
		${WRKSRC}/exosip

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s| =| ?=|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s|docs||g' ${WRKSRC}/oRTP/Makefile.in

post-install:
.if defined(LINPHONE_GUI)
	${INSTALL_MAN} ${WRKSRC}/share/C/linphone.1 ${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/share/linphone.desktop \
		${PREFIX}/share/gnome/applications
.else
	${INSTALL_MAN} ${WRKSRC}/share/C/linphonec.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/share/C/sipomatic.1 ${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/share/linphone.pc ${PREFIX}/libdata/pkgconfig
	@${MKDIR} ${DATADIR}/sounds
	${INSTALL_DATA} ${WRKSRC}/share/*.wav ${DATADIR}/sounds
	@${MKDIR} ${DATADIR}/sounds/rings
	${INSTALL_DATA} ${WRKSRC}/share/rings/*.wav ${DATADIR}/sounds/rings
.endif

.include <bsd.port.post.mk>
