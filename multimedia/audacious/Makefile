# New ports collection makefile for:	audacious
# Date created:			2006-01-01
# Whom:				Zastupov Stepan [RedChrom] <redchrom@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	audacious
PORTVERSION=	3.2.4
CATEGORIES=	multimedia audio
MASTER_SITES=	http://distfiles.audacious-media-player.org/

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	A media player based on BMP and XMMS

LIB_DEPENDS=	mcs.1:${PORTSDIR}/devel/libmcs \
		mowgli.2:${PORTSDIR}/devel/libmowgli \
		xml2.5:${PORTSDIR}/textproc/libxml2

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_XORG=	x11 sm
USE_BZIP2=	yes
USE_GNOME=	gtk20 libglade2
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ARGS=	--disable-gtk3 --disable-chardet

MAN1=		audacious.1 audtool.1

PORTDOCS=	AUTHORS

OPTIONS=	DBUS	"Build with dbus support"			on  \
		GNOME	"Build with gconf support"			off \
		ICONV	"Build with iconv support"			on  \
		NLS	"Native Language Support"			on  \
		EXECINFO "Build with libexecinfo support"		on  \
		SSE2	"Build with SSE2 instruction set"		on  \
		CHARSET	"Build with automatic charset detection"	on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_DBUS)
LIB_DEPENDS+=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
CONFIGURE_ARGS+=--enable-dbus
PLIST_SUB+=	WITH_DBUS=""
.else
CONFIGURE_ARGS+=--disable-dbus
PLIST_SUB+=	WITH_DBUS="@comment "
.endif

.if defined(WITH_EXECINFO) || exists(${LOCALBASE}/lib/libexecinfo.so)
LIB_DEPENDS+=	execinfo.1:${PORTSDIR}/devel/libexecinfo
.endif

.if defined(WITH_GNOME)
USE_GNOME+=	gconf2
CONFIGURE_ARGS+=--enable-gconf
.endif

.if defined(WITH_ICONV) || exists(${LOCALBASE}/lib/libiconv.so)
USE_ICONV=	yes
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if defined(WITHOUT_SSE2)
CONFIGURE_ARGS+=--disable-sse2
.endif

.if defined(WITH_CHARSET)
LIB_DEPENDS+=	guess.1:${PORTSDIR}/textproc/libguess
CONFIGURE_ARGS+=--enable-chardet
.else
CONFIGURE_ARGS+=--disable-chardet
.endif

post-patch:
	@${REINPLACE_CMD} 's|$${libdir}/pkgconfig|$${prefix}/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile
.if defined(WITH_EXECINFO) || exists(${LOCALBASE}/lib/libexecinfo.so)
	@${REINPLACE_CMD} 's|$${REGEX_LIBS}|& -L${LOCALBASE}/lib -lexecinfo|' \
		${WRKSRC}/src/audacious/Makefile
	@${REINPLACE_CMD} 's|-laudcore|-laudcore -L${LOCALBASE}/lib -lexecinfo|' \
		${WRKSRC}/audacious.pc.in
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}
.if defined(WITH_GNOME)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You have installed audacious with gconf support."
	@${ECHO_MSG} "ALL PRESETS will be stored in the gconf database."
	@${ECHO_MSG} ""
.endif

.include <bsd.port.post.mk>
