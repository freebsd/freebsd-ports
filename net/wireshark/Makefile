# Created by: Bill Fumerola <billf@chc-chimes.com>
# $FreeBSD$

PORTNAME?=	wireshark
PORTVERSION=	1.10.6
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.wireshark.org/download/src/ \
		http://ftp.uni-kl.de/pub/wireshark/src/ \
		http://wireshark.askapache.com/download/src/all-versions/ \
		ftp://ftp.uni-kl.de/pub/wireshark/src/ \
		http://prdownloads.sourceforge.net/wireshark/ \
		http://ftp.yz.yamagata-u.ac.jp/pub/network/security/wireshark/src/ \
		ftp://ftp.yz.yamagata-u.ac.jp/pub/network/security/wireshark/src/ \
		http://wireshark.zing.org/download/src/

DISTNAME=	${DATADIR_NAME}-${PORTVERSION}
MAINTAINER=	marcus@FreeBSD.org
COMMENT?=	Powerful network analyzer/capture tool

DATADIR_NAME=	wireshark

USE_PERL5=	build
USE_PYTHON_BUILD=yes
USES=		iconv gettext pkgconfig gmake perl5
USE_BZIP2=	yes
WANT_GNOME=	yes
USE_OPENSSL=	yes
CONFIGURE_ENV=	LIBS="${WIRESHARK_LIBS}"
CONFIGURE_ARGS+=	--program-transform-name="" \
			--with-ssl=${OPENSSLBASE}
USE_LDCONFIG=	yes
DATADIR=	${PREFIX}/share/${DATADIR_NAME}
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-funit-at-a-time

DESKTOP_ENTRIES=	"Wireshark" "Network Protocol Analyzer" \
			"${DATADIR}/hi48-app-wireshark.png" \
			"wireshark" "System;Monitor;GTK;" true

WIRESHARK_LIBS=

.for x in capinfos editcap mergecap rawshark text2pcap dftest randpkt \
    reordercap
.if defined(LITE)
PLIST_SUB+=		${x:U}="@comment $x not installed" \
    			${x:U}_MAN="@comment $x not installed "
CONFIGURE_ARGS+=	--enable-$x=no
.else
PLIST_SUB+=		${x:U}=bin/$x \
    			${x:U}_MAN=""
.endif
.endfor

.if !defined(LITE)
OPTIONS_DEFINE=		RTP SNMP ADNS PCRE IPV6 GEOIP LUA CARES GSSAPI X11 \
			GNUTLS GCRYPT THREADS
OPTIONS_DEFAULT=	SNMP ADNS PCRE IPV6 GEOIP GSSAPI X11

RTP_DESC=		Enable support for playing back RTP streams
ADNS_DESC=		Enable asynchronous DNS lookup support
.endif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
USE_XORG=		x11
.endif

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MX11}
PLIST_SUB+=	WIRESHARK=bin/wireshark WIRESHARK_MAN=""
USE_GNOME+=	gtk20
WIRESHARK_LIBS+=${PTHREAD_LIBS}
.else
PLIST_SUB+=	WIRESHARK="@comment wireshark not built" \
		WIRESHARK_MAN="@comment wireshark not built "
USE_GNOME+=	glib20
CONFIGURE_ARGS+=	--enable-wireshark=no \
			--disable-gtktest
.endif

GNU_CONFIGURE=	yes
LIBTOOLFILES=	configure wiretap/configure
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--enable-ipv6=yes
.else
CONFIGURE_ARGS+=	--enable-ipv6=no
.endif

# XXX - untested
.if ${PORT_OPTIONS:MTHREADS}
CONFIGURE_ARGS+=	--enable-threads
.endif

.if ${PORT_OPTIONS:MPCRE} && !defined(LITE)
LIB_DEPENDS+=	pcre:${PORTSDIR}/devel/pcre
CONFIGURE_ARGS+=	--with-pcre=${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=	--with-pcre=no
.endif

.if ${PORT_OPTIONS:MLUA} && !defined(LITE)
USE_LUA=	5.1
CONFIGURE_ARGS+=--with-lua=${LUA_PREFIX}
PLIST_SUB+=	LUA=""
.else
CONFIGURE_ARGS+=--without-lua
PLIST_SUB+=	LUA="@comment "
.endif

.if ${PORT_OPTIONS:MRTP} && !defined(LITE)
LIB_DEPENDS+=	portaudio:${PORTSDIR}/audio/portaudio
CONFIGURE_ARGS+=--with-portaudio=${LOCALBASE}
WIRESHARK_LIBS+=${PTHREAD_LIBS}
.else
CONFIGURE_ARGS+=--without-portaudio
.endif

.if ${PORT_OPTIONS:MSNMP} && !defined(LITE)
LIB_DEPENDS+=		smi:${PORTSDIR}/net-mgmt/libsmi
CONFIGURE_ARGS+=	--with-libsmi=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--with-libsmi=no
.endif

.if ${PORT_OPTIONS:MADNS} && !defined(LITE)
LIB_DEPENDS+=	adns:${PORTSDIR}/dns/adns
CONFIGURE_ARGS+=	--with-adns=${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=	--with-adns=no
.endif

.if ${PORT_OPTIONS:MCARES} && !defined(LITE)
LIB_DEPENDS+=		cares:${PORTSDIR}/dns/c-ares
CONFIGURE_ARGS+=	--with-c-ares=${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=	--with-c-ares=no
.endif

.if ${PORT_OPTIONS:MGEOIP} && !defined(LITE)
LIB_DEPENDS+=	GeoIP:${PORTSDIR}/net/GeoIP
CONFIGURE_ARGS+=	--with-geoip=${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=	--with-geoip=no
.endif

.if ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=	gnutls:${PORTSDIR}/security/gnutls \
		gcrypt:${PORTSDIR}/security/libgcrypt
CONFIGURE_ARGS+=--with-libgcrypt-prefix=${LOCALBASE} \
		--with-gnutls=yes
.else
CONFIGURE_ARGS+=--with-gnutls=no
.endif

.if ${PORT_OPTIONS:MGCRYPT}
LIB_DEPENDS+=	gcrypt:${PORTSDIR}/security/libgcrypt
CONFIGURE_ARGS+=--with-libgcrypt-prefix=${LOCALBASE}
.endif

.if ! ${PORT_OPTIONS:MGSSAPI}
CONFIGURE_ARGS+=--with-krb5=no
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LUA_INCDIR%%|${LUA_INCDIR}|g ; \
	    	s|-Wl,--as-needed|| ; \
	    	s|%%LUA_LIBDIR%%|${LUA_LIBDIR}|g' \
		${WRKSRC}/configure

post-install:
	${INSTALL_DATA} ${WRKSRC}/image/hi48-app-wireshark.png \
	    ${STAGEDIR}${DATADIR}

.include <bsd.port.post.mk>
