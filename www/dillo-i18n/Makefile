# New ports collection makefile for:	dillo-i18n
# Date created:			2005-12-11
# Whom:               		Thomas-Martin Seck <tmseck@netcologne.de>
#
# $FreeBSD$
#
# Tunables:
# WITH_DILLO_SSL:		enable experimental SSL support
# WITH_DILLO_META-REFRESH:	make dillo accept the meta-refresh tag
# WITHOUT_DILLO_TABS:		disable support for tabbed browsing
# WITHOUT_DILLO_ANTIALIAS:	disable support for antialiased display
#
# TODO:
# SSL support is currently partly broken in this version of the i18n dillo:
# On FreeBSD 4 with OpenSSL 0.9.7d, the configure script uses checks that are
# too strict. On FreeBSD 5 and 6 it seems to work OK.

PORTNAME=	dillo
PORTVERSION=	${DILLOVERSION}.${I18NVERSION}
CATEGORIES=	www ipv6
MASTER_SITES=	http://teki.jpn.ph/pc/software/
PKGNAMESUFFIX=	-i18n
DISTNAME=	${PORTNAME}-${DILLOVERSION}-i18n-misc-${I18NVERSION}

MAINTAINER=	tmseck@netcologne.de
COMMENT=	A fast, small graphical Web browser with support for i18n

RUN_DEPENDS=	wget:${PORTSDIR}/ftp/wget
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

DILLOVERSION=	0.8.6
I18NVERSION=	20060516

USE_BZIP2=	yes
USE_GNOME=	gnometarget gtk12
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--enable-cookies --enable-ipv6 --enable-threaded-dns \
		--disable-dlgui \
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
# Note: the configure script will deactivate SSL support on 4.x systems.
# This might get fixed someday so I activate this option unconditionally.
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
	@${ECHO_CMD} "   commandline to make dillo respect the meta-refresh tag."
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
	@${ECHO_CMD} ""

.include <bsd.port.mk>
