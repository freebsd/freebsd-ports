# New ports collection makefile for:   ettercap
# Date created:        19 February 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=		ettercap
PORTVERSION=		0.7.3
DISTVERSIONPREFIX=	NG-
PORTREVISION=	8
PORTEPOCH=		1
CATEGORIES=		net-mgmt security
MASTER_SITES=		SF/${PORTNAME}/${PORTNAME}/NG-${PORTVERSION} \
			${MASTER_SITE_PACKETSTORM:S:%SUBDIR%:sniffers/ettercap:}

MAINTAINER=	mnag@FreeBSD.org
COMMENT=	A network sniffer/interceptor/injector/logger for switched LANs

BUILD_DEPENDS=	${LIBNET_CONFIG}:${PORTSDIR}/net/libnet

OPTIONS=	GTK	"Build with GTK2+ GUI"	on \
		ICONV	"Build with support for UTF-8"	on \
		PLUGINS	"Build with ettercap plugins"	on \
		SSL	"Build with support for SSH1 and SSL decryption"	on \
		PCRE	"Build with PCRE regexps in filters"	on

WANT_GNOME=	yes
USE_AUTOTOOLS=	libltdl:22
GNU_CONFIGURE=	yes

MAN5=		etter.conf.5
MAN8=		ettercap.8 ettercap_curses.8 etterfilter.8 etterlog.8
DOCS=		AUTHORS CHANGELOG README README.BINARIES README.BUGS \
		README.CVS README.PLATFORMS THANKS TODO TODO.TESTING \
		doc/capture doc/decoders doc/dissectors doc/threads

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet11-config

.include <bsd.port.pre.mk>

CFLAGS+=		${PTHREAD_CFLAGS}
CPPFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
			LIBS="${LDFLAGS}"
CONFIGURE_ARGS+=	--enable-plugins

.if !defined(WITHOUT_GTK)
USE_GNOME=		glib20 atk pango gtk20
PKGNAMESUFFIX+=		-gtk2
CONFIGURE_ARGS+=	--enable-gtk
.else
CONFIGURE_ARGS+=	--disable-gtk
.endif

.if !defined(WITHOUT_ICONV)
USE_ICONV=		yes
CONFIGURE_ARGS+=	--with-iconv=${LOCALBASE}
.endif

.if !defined(WITHOUT_PCRE)
LIB_DEPENDS+=		pcre.0:${PORTSDIR}/devel/pcre
CONFIGURE_ARGS+=	--with-libpcre=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-libpcre
.endif

.if !defined(WITHOUT_PLUGINS)
MAN8+=			ettercap_plugins.8
DOCS+=			doc/plugins
CONFIGURE_ARGS+=	--enable-plugins
PLIST_SUB+=		PLUGINS=""
.else
CONFIGURE_ARGS+=	--disable-plugins
PLIST_SUB+=		PLUGINS="@comment "
.endif

.if !defined(WITHOUT_SSL)
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
CONFIGURE_ARGS+=	--with-openssl=${OPENSSLBASE}
.else
CONFIGURE_ARGS+=	--without-openssl
.endif

post-patch:
	@${REINPLACE_CMD} -Ee \
		's|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|; \
		 s|test -f /usr/include/libnet\.h|${TRUE}|; \
		 s|(LNETINC=).*|\1"`${LIBNET_CONFIG} --cflags`"|; \
		 s|(LNETLIB=).*|\1"`${LIBNET_CONFIG} --libs`"|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -E -e 's|(^pkgdatadir.+=).+|\1 ${DATADIR}|' \
		${WRKSRC}/share/Makefile.in
# Fix objformat
	@${REINPLACE_CMD} -E -e 's|(^.*=).*/usr/bin/objformat.*|\1"elf"|' \
		${WRKSRC}/aclocal.m4 ${WRKSRC}/configure

post-install:
	@${INSTALL_DATA} ${WRKSRC}/share/etter.conf \
		${PREFIX}/etc/etter.conf.sample
.	if !exists(${PREFIX}/etc/etter.conf)
		@${INSTALL_DATA} ${WRKSRC}/share/etter.conf ${PREFIX}/etc/etter.conf
.	endif
.	if !defined(NOPORTDOCS)
		@${MKDIR} ${DOCSDIR}
.		for i in ${DOCS}
			@${INSTALL_DATA} ${WRKSRC}/$i ${DOCSDIR}
.		endfor
.	endif

.include <bsd.port.post.mk>
