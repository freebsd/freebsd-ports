# New ports collection makefile for:	audacious
# Date created:			2006-01-01
# Whom:				Zastupov Stepan [RedChrom] <redchrom@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	audacious
PORTVERSION=	2.2
CATEGORIES=	multimedia audio
MASTER_SITES=	http://distfiles.atheme.org/
MASTER_SITE_SUBDIR=oliver
EXTRACT_SUFX=	.tgz

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	A media player based on BMP and XMMS

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_XORG=	x11 sm
USE_GNOME=	gtk20 libglade2
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-libintl-prefix=${LOCALBASE}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		audacious2.1 audtool2.1

LIB_DEPENDS=	mcs.1:${PORTSDIR}/devel/libmcs \
		mowgli.2:${PORTSDIR}/devel/libmowgli

PORTDOCS=	README AUTHORS NEWS

OPTIONS=	CHARSET	"Build with automatic charset detection"	off \
		DBUS	"Build with dbus support"			on  \
		GNOME	"Build with gconf support"			off \
		NLS	"Native Language Support"			on  \
		XML	"Build with xml support"			on  \
		EXECINFO "Build with libexecinfo support"		on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_DBUS)
LIB_DEPENDS+=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
CONFIGURE_ARGS+=--enable-dbus
PLIST_SUB+=	WITH_DBUS=""
.else
CONFIGURE_ARGS+=--disable-dbus
PLIST_SUB+=	WITH_DBUS="@comment "
.endif

.if defined(WITH_CHARSET)
CONFIGURE_ARGS+=--enable-chardet
.endif

.if defined(WITH_EXECINFO) || exists(${LOCALBASE}/lib/libexecinfo.so)
LIB_DEPENDS+=	execinfo.1:${PORTSDIR}/devel/libexecinfo
.endif

.if defined(WITH_GNOME)
USE_GNOME+=	gconf2
CONFIGURE_ARGS+=--enable-gconf
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if !defined(WITHOUT_XML)
LIB_DEPENDS+=	xml2.5:${PORTSDIR}/textproc/libxml2
.else
CONFIGURE_ARGS+=--with-xml-prefix=/
.endif

post-patch:
	@${REINPLACE_CMD} 's|$${libdir}/pkgconfig|$${prefix}/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile
#	@${REINPLACE_CMD} 's|+= $${LIB_CPPFLAGS} -I..|= -I.. $${LIB_[8$CPPFLAGS}|' \
#		${WRKSRC}/src/libid3tag/Makefile
	@${REINPLACE_CMD} 's|CPPFLAGS +=|CPPFLAGS =|g' \
		${WRKSRC}/src/libid3tag/Makefile \
		${WRKSRC}/src/libaudgui/Makefile
	@${REINPLACE_CMD} 's|FMT_FIXED32,|FMT_FIXED32|g; \
		s|OUTPUT_PLUGIN_INIT_FOUND_DEVICES,|OUTPUT_PLUGIN_INIT_FOUND_DEVICES|g' \
		${WRKSRC}/src/audacious/plugin.h
	@${REINPLACE_CMD} 's|VALUE_NULL,|VALUE_NULL|g' \
		${WRKSRC}/src/audacious/preferences.h
	@${REINPLACE_CMD} 's|glib-2\.0/||g' \
		${WRKSRC}/src/libaudtag/util.h \
		${WRKSRC}/src/libaudtag/wma/guid.c \
		${WRKSRC}/src/libaudtag/wma/wma.c \
		${WRKSRC}/src/libaudtag/wma/wma_fmt.h
.if defined(WITH_EXECINFO) || exists(${LOCALBASE}/lib/libexecinfo.so)
	@${REINPLACE_CMD} 's|$${REGEX_LIBS}|& -L${LOCALBASE}/lib -lexecinfo|' \
		${WRKSRC}/src/audacious/Makefile
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
