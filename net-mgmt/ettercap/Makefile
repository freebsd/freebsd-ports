# New ports collection makefile for:   ettercap
# Date created:        19 February 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	ettercap
PORTVERSION=	0.7.4
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	net-mgmt security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}-Lazarus \
		${MASTER_SITE_PACKETSTORM:S:%SUBDIR%:sniffers/ettercap:}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	A network sniffer/interceptor/injector/logger for switched LANs

BUILD_DEPENDS=	${LIBNET_CONFIG}:${PORTSDIR}/net/libnet

OPTIONS=	GTK	"Build with GTK2+ GUI" on \
		ICONV	"Build with support for UTF-8" on \
		PCRE	"Build with PCRE regexps in filters" on \
		PLUGINS	"Build with ettercap plugins" on \
		SSL	"Build with support for SSH1 and SSL decryption" on

CFLAGS+=	${PTHREAD_CFLAGS}
CONFIGURE_ENV=	LIBS="${LDFLAGS}"
CONFIGURE_ARGS=	--enable-plugins
CPPFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_JOBS_UNSAFE=	yes
USE_AUTOTOOLS=	libltdl libtool
USE_BISON=	build
WANT_GNOME=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

MAN5=		etter.conf.5
MAN8=		ettercap.8 ettercap_curses.8 etterfilter.8 etterlog.8
DOCS=		AUTHORS CHANGELOG README README.BINARIES README.BUGS \
		README.GIT README.PLATFORMS THANKS TODO TODO.TESTING \
		doc/capture doc/decoders doc/dissectors doc/threads

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet11-config

.include <bsd.port.options.mk>

.if !defined(WITHOUT_GTK)
USE_GNOME=	atk glib20 gtk20 pango
PKGNAMESUFFIX+=	-gtk2
CONFIGURE_ARGS+=--enable-gtk
.else
CONFIGURE_ARGS+=--disable-gtk
.endif

.if !defined(WITHOUT_ICONV)
USE_ICONV=	yes
CONFIGURE_ARGS+=--with-iconv=${LOCALBASE}
.endif

.if !defined(WITHOUT_PCRE)
LIB_DEPENDS+=	pcre.1:${PORTSDIR}/devel/pcre
CONFIGURE_ARGS+=--with-libpcre=${LOCALBASE}
.else
CONFIGURE_ARGS+=--without-libpcre
.endif

.if !defined(WITHOUT_PLUGINS)
MAN8+=		ettercap_plugins.8
DOCS+=		doc/plugins
CONFIGURE_ARGS+=--enable-plugins
PLIST_SUB+=	PLUGINS=""
.else
CONFIGURE_ARGS+=--disable-plugins
PLIST_SUB+=	PLUGINS="@comment "
.endif

.if !defined(WITHOUT_SSL)
USE_OPENSSL=	yes
CONFIGURE_ARGS+=--with-openssl=${OPENSSLBASE}
.else
CONFIGURE_ARGS+=--without-openssl
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
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
