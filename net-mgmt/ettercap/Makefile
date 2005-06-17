# New ports collection makefile for:   ettercap
# Date created:        19 February 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	ettercap
PORTVERSION=	0.7.3
PORTREVISION=	0
DISTVERSIONPREFIX=	NG-
PORTEPOCH=	1
CATEGORIES=	net-mgmt security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED} \
		${MASTER_SITE_PACKETSTORM:S:%SUBDIR%:sniffers/ettercap:}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A network sniffer/interceptor/injector/logger for switched LANs

BUILD_DEPENDS=	${LOCALBASE}/include/libnet/libnet-types.h:${PORTSDIR}/net/libnet-devel
.if !defined(WITHOUT_PCRE)
LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre
.endif

GNU_CONFIGURE=	yes
USE_LIBTOOL_VER=15
USE_REINPLACE=	yes
.if !defined(WITHOUT_GTK)
USE_GNOME=	glib20 atk pango gtk20
PKGNAMESUFFIX=	-gtk2
.endif
.if !defined(WITHOUT_ICONV)
USE_ICONV=	yes
.endif
.if !defined(WITHOUT_PLUGINS)
USE_LIBLTDL=	yes
.endif
.if !defined(WITHOUT_SSL)
USE_OPENSSL=	yes
.endif

MAN5=		etter.conf.5
MAN8=		ettercap.8 ettercap_curses.8 etterfilter.8 etterlog.8
DOCS=		AUTHORS CHANGELOG README README.BINARIES README.BUGS \
		README.CVS README.PLATFORMS THANKS TODO TODO.TESTING \
		doc/capture doc/decoders doc/dissectors doc/threads
.if !defined(WITHOUT_PLUGINS)
MAN8+=		ettercap_plugins.8
DOCS+=		doc/plugins
.endif

.include <bsd.port.pre.mk>

CFLAGS+=		${PTHREAD_CFLAGS}
CPPFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS+=	--enable-plugins --with-libnet=${LOCALBASE}
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

.if ${OSVERSION} < 502111
BUILD_DEPENDS+=		${LOCALBASE}/lib/libpcap.a:${PORTSDIR}/net/libpcap
CONFIGURE_ARGS+=	--with-libpcap=${LOCALBASE}
.endif

.if !defined(WITHOUT_GTK)
CONFIGURE_ARGS+=	--enable-gtk
.else
CONFIGURE_ARGS+=	--disable-gtk
.endif
.if !defined(WITHOUT_ICONV)
CONFIGURE_ARGS+=	--with-iconv=${LOCALBASE}
.endif
.if !defined(WITHOUT_PCRE)
CONFIGURE_ARGS+=	--with-libpcre=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-libpcre
.endif
.if !defined(WITHOUT_PLUGINS)
PLIST_SUB+=		PLUGINS=""
CONFIGURE_ARGS+=	--enable-plugins
.else
CONFIGURE_ARGS+=	--disable-plugins
PLIST_SUB+=		PLUGINS="@comment "
.endif
.if !defined(WITHOUT_SSL)
CONFIGURE_ARGS+=	--with-openssl=${OPENSSLBASE}
.else
CONFIGURE_ARGS+=	--without-openssl
.endif

pre-everything::
.if !defined(WITHOUT_GTK) || !defined(WITHOUT_ICONV) || \
	!defined(WITHOUT_PCRE) || !defined(WITHOUT_PLUGINS) || \
	!defined(WITHOUT_SSL)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may use the following build option(s):"
	@${ECHO_MSG} ""
.if !defined(WITHOUT_GTK)
	@${ECHO_MSG} "WITHOUT_GTK=yes		builds without GTK2+ GUI"
.endif
.if !defined(WITHOUT_ICONV)
	@${ECHO_MSG} "WITHOUT_ICONV=yes	builds without support for UTF-8"
.endif
.if !defined(WITHOUT_PCRE)
	@${ECHO_MSG} "WITHOUT_PCRE=yes	builds without support for perl regexps in filters"
.endif
.if !defined(WITHOUT_PLUGINS)
	@${ECHO_MSG} "WITHOUT_PLUGINS=yes	builds without ettercap plugins"
.endif
.if !defined(WITHOUT_SSL)
	@${ECHO_MSG} "WITHOUT_SSL=yes		builds without support for SSH1 and SSL decryption"
.endif
	@${ECHO_MSG} ""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -E -e 's|(^pkgdatadir.+=).+|\1 ${DATADIR}|' \
		${WRKSRC}/share/Makefile.in

post-install:
	@${INSTALL_DATA} ${WRKSRC}/share/etter.conf \
		${PREFIX}/etc/etter.conf.sample
.if !exists(${PREFIX}/etc/etter.conf)
	@${INSTALL_DATA} ${WRKSRC}/share/etter.conf ${PREFIX}/etc/etter.conf
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/$i ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
