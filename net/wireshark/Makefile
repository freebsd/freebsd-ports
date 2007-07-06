# New ports collection makefile for:   ethereal
# Date created:        10 August 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $FreeBSD$
#

PORTNAME?=	wireshark
PORTVERSION=	0.99.6
PORTREVISION?=	0
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.wireshark.org/download/src/
DISTNAME=	${DATADIR_NAME}-${PORTVERSION}

MAINTAINER=	marcus@FreeBSD.org
COMMENT?=	A powerful network analyzer/capture tool

DATADIR_NAME=	wireshark

USE_PERL5_BUILD=yes
USE_PYTHON_BUILD=yes
USE_ICONV=	yes
USE_BZIP2=	yes
USE_GCC=	3.4+
USE_GMAKE=	yes
USE_GNOME=	gnometarget
WANT_GNOME=	yes
USE_OPENSSL=	yes
CONFIGURE_ENV=	MIBDIRS="/dev/null" \
		LIBS="${WIRESHARK_LIBS}"
CONFIGURE_ARGS+=	--program-transform-name="" \
			--with-ssl=${OPENSSLBASE} \
			--mandir=${MANPREFIX}/man
MAKE_ENV=	MIBDIRS="/dev/null"
USE_LDCONFIG=	yes
DATADIR=	${PREFIX}/share/${DATADIR_NAME}
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-funit-at-a-time

WIRESHARK_LIBS=

.for x in capinfos editcap idl2wrs mergecap text2pcap
.if defined(LITE)
PLIST_SUB+=		${x:U}="@comment $x not installed"
CONFIGURE_ARGS+=	--enable-$x=no
.else
PLIST_SUB+=		${x:U}=bin/$x
MAN1+=			$x.1
.endif
.endfor

.for x in dftest randpkt
.if defined(LITE)
PLIST_SUB+=	${x:U}="@comment $x not installed"
CONFIGURE_ARGS+=	--enable-$x=no
.else
PLIST_SUB+=	${x:U}=bin/$x
.endif
.endfor

.if !defined(WITHOUT_X11)
USE_XLIB=	yes
.endif

.if !defined(LITE)
OPTIONS=	RTP "Enable support for playing back RTP streams" off \
		SNMP "Enable SNMP OID translation support" on \
		ADNS "Enable asynchronous DNS lookup support" on \
		PCRE "Enable regular expression matching support" on
.endif

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_X11)
MAN1+=		wireshark.1
PLIST_SUB+=	WIRESHARK=bin/wireshark
.if defined(WITHOUT_GTK2)
USE_GNOME+=	gtk12
CONFIGURE_ARGS+=	--disable-gtk2
.else
USE_GNOME+=	gtk20
WIRESHARK_LIBS+=${PTHREAD_LIBS}
.endif
.else
PLIST_SUB+=	WIRESHARK="@comment wireshark not built"
USE_GNOME+=	glib12
CONFIGURE_ARGS+=	--enable-wireshark=no \
			--disable-gtktest \
			--with-gtk-prefix=/nonexistent \
			--disable-gtk2
.endif

GNU_CONFIGURE=	yes
LIBTOOLFILES=	configure wiretap/configure
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

.if !defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6=yes
.else
CONFIGURE_ARGS+=	--enable-ipv6=no
.endif

# XXX - untested
.if defined(WITH_THREADS)
CONFIGURE_ARGS+=	--enable-threads
.endif

.if !defined(WITHOUT_PCRE) && !defined(LITE)
LIB_DEPENDS+=	pcre.0:${PORTSDIR}/devel/pcre
CONFIGURE_ARGS+=	--with-pcre=${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=	--with-pcre=no
.endif

#.if defined(WITH_LUA) && !defined(LITE)
#USE_LUA=	5.1
#CONFIGURE_ARGS+=--with-lua=${LUA_PREFIX}
#PLIST_SUB+=	LUA=""
#.else
CONFIGURE_ARGS+=--without-lua
#PLIST_SUB+=	LUA="@comment "
#.endif

.if defined(WITH_RTP) && !defined(LITE)
LIB_DEPENDS+=	portaudio:${PORTSDIR}/audio/portaudio
CONFIGURE_ARGS+=--with-portaudio=${LOCALBASE}
WIRESHARK_LIBS+=${PTHREAD_LIBS}
.else
CONFIGURE_ARGS+=--without-portaudio
.endif

.if !defined(WITHOUT_SNMP) && !defined(LITE)
LIB_DEPENDS+=	netsnmp.10:${PORTSDIR}/net-mgmt/net-snmp
CONFIGURE_ARGS+=	--with-net-snmp=${LOCALBASE}/bin/net-snmp-config \
			--without-ucd-snmp
.else
CONFIGURE_ARGS+=	--with-ucd-snmp=no --with-net-snmp=no
.endif

.if !defined(WITHOUT_ADNS) && !defined(LITE)
LIB_DEPENDS+=	adns.1:${PORTSDIR}/dns/adns
CONFIGURE_ARGS+=	--with-adns=${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=	--with-adns=no
.endif

.if exists(${LOCALBASE}/lib/libgnutls.so) || defined(WITH_GNUTLS)
LIB_DEPENDS+=	gnutls.13:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=--with-libgnutls-prefix=${LOCALBASE}
.endif

.if exists(${LOCALBASE}/lib/libgcrypt.so) || defined(WITH_LIBGCRYPT)
LIB_DEPENDS+=	gcrypt.13:${PORTSDIR}/security/libgcrypt
CONFIGURE_ARGS+=--with-libgcrypt-prefix=${LOCALBASE}
.endif

MAN1+=	dumpcap.1 tshark.1
MAN4+=	wireshark-filter.4

post-patch:
	@${REINPLACE_CMD} -e 's|lua5\.1|lua${LUA_VER_STR}|g ; \
	    	s|NETSNMPCNFIG|NETSNMPCONFIG| ; \
	    	s|-llua${LUA_VER_STR}|${LUA_LIBDIR}/liblua.a|g' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
