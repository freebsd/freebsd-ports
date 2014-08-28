# Created by: Bill Fumerola <billf@chc-chimes.com>
# $FreeBSD$

PORTNAME?=	wireshark
PORTVERSION=	1.12.0
PORTREVISION=	2
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
USES=		iconv gettext pkgconfig gmake perl5 tar:bzip2 libtool \
    		python:build
WANT_GNOME=	yes
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--program-transform-name="" \
			--with-ssl=${OPENSSLBASE} \
			--with-qt=no
USE_LDCONFIG=	yes
DATADIR=	${PREFIX}/share/${DATADIR_NAME}
CFLAGS+=	-funit-at-a-time
LIBS+=		-L${LOCALBASE}/lib

DESKTOP_ENTRIES=	"Wireshark" "Network Protocol Analyzer" \
			"${DATADIR}/hi48-app-wireshark.png" \
			"wireshark" "System;Monitor;GTK;" true

.for x in capinfos editcap mergecap rawshark text2pcap dftest randpkt \
    reordercap captype
.if defined(LITE)
PLIST_SUB+=		${x:tu}="@comment $x not installed" \
    			${x:tu}_MAN="@comment $x not installed "
CONFIGURE_ARGS+=	--enable-$x=no
.else
PLIST_SUB+=		${x:tu}=bin/$x \
    			${x:tu}_MAN=""
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

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
PLIST_SUB+=	WIRESHARK=bin/wireshark WIRESHARK_MAN=""
USE_GNOME+=	gtk30
CONFIGURE_ARGS+=--with-gtk3=yes
.else
PLIST_SUB+=	WIRESHARK="@comment wireshark not built" \
		WIRESHARK_MAN="@comment wireshark not built "
USE_GNOME+=	glib20
CONFIGURE_ARGS+=	--enable-wireshark=no \
			--disable-gtktest
.endif

GNU_CONFIGURE=	yes
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
LIB_DEPENDS+=	libpcre.so:${PORTSDIR}/devel/pcre
CONFIGURE_ARGS+=	--with-pcre=${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=	--with-pcre=no
.endif

.if ${PORT_OPTIONS:MLUA} && !defined(LITE)
USES+=		lua:51
CONFIGURE_ARGS+=--with-lua=${PREFIX}
CPPFLAGS+=	-I${LUA_INCDIR}
PLIST_SUB+=	LUA=""
.else
CONFIGURE_ARGS+=--without-lua
PLIST_SUB+=	LUA="@comment "
.endif

.if ${PORT_OPTIONS:MRTP} && !defined(LITE)
LIB_DEPENDS+=	libportaudio.so:${PORTSDIR}/audio/portaudio
CONFIGURE_ARGS+=--with-portaudio=${LOCALBASE}
.else
CONFIGURE_ARGS+=--without-portaudio
.endif

.if ${PORT_OPTIONS:MSNMP} && !defined(LITE)
LIB_DEPENDS+=		libsmi.so:${PORTSDIR}/net-mgmt/libsmi
CONFIGURE_ARGS+=	--with-libsmi=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--with-libsmi=no
.endif

.if ${PORT_OPTIONS:MADNS} && !defined(LITE)
LIB_DEPENDS+=		libadns.so:${PORTSDIR}/dns/adns
CONFIGURE_ARGS+=	--with-adns=${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=	--with-adns=no
.endif

.if ${PORT_OPTIONS:MCARES} && !defined(LITE)
LIB_DEPENDS+=		libcares.so:${PORTSDIR}/dns/c-ares
CONFIGURE_ARGS+=	--with-c-ares=${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=	--with-c-ares=no
.endif

.if ${PORT_OPTIONS:MGEOIP} && !defined(LITE)
LIB_DEPENDS+=		libGeoIP.so:${PORTSDIR}/net/GeoIP
CONFIGURE_ARGS+=	--with-geoip=${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=	--with-geoip=no
.endif

.if ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=	libgnutls.so:${PORTSDIR}/security/gnutls \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt
CONFIGURE_ARGS+=--with-libgcrypt-prefix=${LOCALBASE} \
		--with-gnutls=yes
.else
CONFIGURE_ARGS+=--with-gnutls=no
.endif

.if ${PORT_OPTIONS:MGCRYPT}
LIB_DEPENDS+=	libgcrypt.so:${PORTSDIR}/security/libgcrypt
CONFIGURE_ARGS+=--with-libgcrypt-prefix=${LOCALBASE}
.endif

.if ! ${PORT_OPTIONS:MGSSAPI}
CONFIGURE_ARGS+=--with-krb5=no
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|llua|llua-${LUA_VER}|g ; \
		s|-Wl,--as-needed|| ' \
		${WRKSRC}/configure

post-install:
	${INSTALL_DATA} ${WRKSRC}/image/hi48-app-wireshark.png \
	    ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
