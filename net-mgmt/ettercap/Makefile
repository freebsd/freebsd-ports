# Created by: George Reid <greid@ukug.uk.freebsd.org>
# $FreeBSD$

PORTNAME=	ettercap
PORTVERSION=	0.7.4.1
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	net-mgmt security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION:R}-Lazarus \
		${MASTER_SITE_PACKETSTORM:S:%SUBDIR%:sniffers/ettercap:}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Network sniffer/interceptor/injector/logger for switched LANs

LIB_DEPENDS=	net:${PORTSDIR}/net/libnet

# GTK -> GTK2, ICONV -> UTF8
OPTIONS_DEFINE=	DOCS GTK2 PCRE PLUGINS SSL UTF8
OPTIONS_DEFAULT=GTK2 PCRE PLUGINS SSL UTF8
PCRE_DESC=	Use PCRE in filters
SSL_DESC=	SSH1 and SSL decryption support

CFLAGS+=	${PTHREAD_CFLAGS}
CONFIGURE_ENV=	LIBS="${LDFLAGS}"
CONFIGURE_ARGS=	--enable-plugins
CPPFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_JOBS_UNSAFE=	yes
USE_AUTOTOOLS=	libltdl libtool
USES=		bison
WANT_GNOME=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

DOCS=		AUTHORS CHANGELOG README README.BINARIES README.BUGS \
		README.GIT README.PLATFORMS THANKS TODO TODO.TESTING \
		doc/capture doc/decoders doc/dissectors doc/threads
MAN5=		etter.conf.5
MAN8=		ettercap.8 ettercap_curses.8 etterfilter.8 etterlog.8

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet11-config

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTK2}
PKGNAMESUFFIX?=	-gtk2
CONFIGURE_ARGS+=--enable-gtk
USE_GNOME=	atk glib20 gtk20 pango
.else
CONFIGURE_ARGS+=--disable-gtk
.endif

.if ${PORT_OPTIONS:MUTF8}
CONFIGURE_ARGS+=--with-iconv=${LOCALBASE}
USES+=		iconv
.endif

.if ${PORT_OPTIONS:MPCRE}
LIB_DEPENDS+=	pcre:${PORTSDIR}/devel/pcre
CONFIGURE_ARGS+=--with-libpcre=${LOCALBASE}
.else
CONFIGURE_ARGS+=--without-libpcre
.endif

.if ${PORT_OPTIONS:MPLUGINS}
CONFIGURE_ARGS+=--enable-plugins
DOCS+=		doc/plugins
MAN8+=		ettercap_plugins.8
PLIST_SUB+=	PLUGINS=""
.else
CONFIGURE_ARGS+=--disable-plugins
PLIST_SUB+=	PLUGINS="@comment "
.endif

.if ${PORT_OPTIONS:MSSL}
CONFIGURE_ARGS+=--with-openssl=${OPENSSLBASE}
USE_OPENSSL=	yes
.else
CONFIGURE_ARGS+=--without-openssl
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
BROKEN=		does not compile on FreeBSD 7.X
.endif

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|' \
		-e 's|test -f /usr/include/libnet\.h|${TRUE}|' \
		-e 's|(LNETINC=).*|\1"`${LIBNET_CONFIG} --cflags`"|' \
		-e 's|(LNETLIB=).*|\1"`${LIBNET_CONFIG} --libs`"|' \
			${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -E \
		-e 's|(^pkgdatadir.+=).+|\1 ${DATADIR}|' \
		-e '/^install-exec-am:/ s|: .*$$|:|'\
	       		${WRKSRC}/share/Makefile.in
# Fix objformat
	@${REINPLACE_CMD} -E -e 's|(^.*=).*/usr/bin/objformat.*|\1"elf"|' \
		${WRKSRC}/aclocal.m4 ${WRKSRC}/configure

post-install:
	${INSTALL_DATA} ${WRKSRC}/share/etter.conf ${PREFIX}/etc/etter.conf.sample
.if !exists(${PREFIX}/etc/etter.conf)
	${INSTALL_DATA} ${WRKSRC}/share/etter.conf ${PREFIX}/etc/etter.conf
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}/
.endif

.include <bsd.port.post.mk>
