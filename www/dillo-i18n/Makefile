# New ports collection makefile for:	dillo-i18n
# Date created:			2005-12-11
# Whom:               		Thomas-Martin Seck <tmseck@netcologne.de>
#
# $FreeBSD$
#
# Tunables:
# WITH_DILLO_SSL:		enable experimental SSL support
# WITH_DILLO_META-REFRESH:	make Dillo accept the meta-refresh tag
# WITHOUT_DILLO_TABS:		disable support for tabbed browsing
# WITHOUT_DILLO_ANTIALIAS:	disable support for antialiased display
# WITH_DILLO_DLGUI:		enable experimental FLTK2 based gui for file
# 				downloads
# WITHOUT_DILLO_IPV6:		disable IPv6 support
#

PORTNAME=	dillo
PORTVERSION=	${DILLOVERSION}.${I18NVERSION}
PORTREVISION=	6
CATEGORIES=	www ipv6
MASTER_SITES=	http://teki.jpn.ph/pc/software/
PKGNAMESUFFIX=	-i18n
DISTNAME=	${PORTNAME}-${DILLOVERSION}-i18n-misc-${I18NVERSION}

MAINTAINER=	tmseck@netcologne.de
COMMENT=	A fast, small graphical Web browser with support for i18n

RUN_DEPENDS=	wget:${PORTSDIR}/ftp/wget
LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		png.6:${PORTSDIR}/graphics/png

DILLOVERSION=	0.8.6
I18NVERSION=	20060709

USE_BZIP2=	yes
USE_GNOME=	gnometarget gtk12
USE_GMAKE=	yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--enable-cookies --enable-threaded-dns \
		--libdir=${PREFIX}/libexec

CONFLICTS=	dillo-[0-9].[0-9].[0-9]*

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB=	NLS=""
CONFIGURE_ARGS+=	--enable-nls
.else
PLIST_SUB=	NLS="@comment "
CONFIGURE_ARGS+=	--disable-nls
.endif

.if defined(WITH_DILLO_SSL)
CONFIGURE_ARGS+=	--enable-ssl
USE_OPENSSL=	yes
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif

.if defined(WITH_DILLO_META-REFRESH)
CONFIGURE_ARGS+=	--enable-meta-refresh
.else
CONFIGURE_ARGS+=	--disable-meta-refresh
.endif

.if defined(WITHOUT_DILLO_TABS)
CONFIGURE_ARGS+=	--disable-tabs
.else
CONFIGURE_ARGS+=	--enable-tabs
.endif

.if !defined(WITHOUT_DILLO_ANTIALIAS)
LIB_DEPENDS+=	Xft.2:${PORTSDIR}/x11-fonts/libXft
CONFIGURE_ARGS+=	--enable-anti-alias
.else
CONFIGURE_ARGS+=	--disable-anti-alias
.endif

.if defined(WITH_DILLO_DLGUI)
CONFIGURE_ARGS+=	--enable-dlgui
BUILD_DEPENDS+=	fltk>=2.0.r4825:${PORTSDIR}/x11-toolkits/fltk2
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=	--disable-dlgui
.endif

.if !defined(WITHOUT_DILLO_IPV6) && !defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|g ; \
		 s|-D_THREAD_SAFE|${PTHREAD_CFLAGS}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|dillorc|dillorc.sample|g' ${WRKSRC}/Makefile.in
	@${CP} ${WRKSRC}/dillorc ${WRKSRC}/dillorc.sample

pre-configure:
.if !defined(WITH_DILLO_SSL)
	@${ECHO_CMD} ""
	@${ECHO_CMD} "   Set WITH_DILLO_SSL=yes in your make environment or on the"
	@${ECHO_CMD} "   commandline to enable experimental SSL support."
.endif
.if !defined(WITH_DILLO_META-REFRESH)
	@${ECHO_CMD} ""
	@${ECHO_CMD} "   Set WITH_DILLO_META-REFRESH=yes in your make environment or on the"
	@${ECHO_CMD} "   commandline to make Dillo respect the meta-refresh tag."
.endif
.if !defined(WITHOUT_DILLO_TABS)
	@${ECHO_CMD} ""
	@${ECHO_CMD} "   Set WITHOUT_DILLO_TABS=yes in your make environment or on the"
	@${ECHO_CMD} "   commandline to disable support for tabbed browsing."
.endif
.if !defined(WITHOUT_DILLO_ANTIALIAS)
	@${ECHO_CMD} ""
	@${ECHO_CMD} "   Set WITHOUT_DILLO_ANTIALIAS=yes in your make environment or on the"
	@${ECHO_CMD} "   commandline to disable support for antialiased fonts."
.endif
.if !defined(WITH_DILLO_DLGUI)
	@${ECHO_CMD} ""
	@${ECHO_CMD} "   Set WITH_DILLO_DLGUI=yes in your make environment or on the"
	@${ECHO_CMD} "   commandline to enable a FLTK2 based gui for download operations."
.endif
.if !defined(WITHOUT_DILLO_IPV6) && !defined(WITHOUT_IPV6)
	@${ECHO_CMD} ""
	@${ECHO_CMD} "   Set WITHOUT_DILLO_IPV6=yes (or WITHOUT_IPV6=yes) in your make"
	@${ECHO_CMD} "   environment or on the commandline to disable IPv6 support."
.endif
	@${ECHO_CMD} ""

.include <bsd.port.mk>
