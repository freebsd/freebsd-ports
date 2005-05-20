# New ports collection makefile for:   ethereal
# Date created:        10 August 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $FreeBSD$
#

PORTNAME=	ethereal
PORTVERSION=	0.10.11
PORTREVISION=	1
CATEGORIES=	net ipv6
MASTER_SITES=	ftp://ftp.ethereal.com/pub/ethereal/all-versions/ \
		ftp://gd.tuwien.ac.at/infosys/security/ethereal/all-versions/ \
		ftp://ftp.sunet.se/pub/network/monitoring/ethereal/all-versions/ \
		ftp://ftp.mirrors.wiretapped.net/pub/security/packet-capture/ethereal/all-versions/ \
		http://www.mirrors.wiretapped.net/pub/security/packet-capture/ethereal/all-versions/

MAINTAINER=	marcus@FreeBSD.org
COMMENT?=	A powerful network analyzer/capture tool

USE_PERL5_BUILD=yes
USE_PYTHON_BUILD=yes
USE_ICONV=	yes
USE_BZIP2=	yes
USE_GNOME=	gnometarget
WANT_GNOME=	yes
CONFIGURE_ARGS+=	--program-transform-name=""
INSTALLS_SHLIB=	yes

.for x in capinfos editcap idl2eth mergecap text2pcap
.if defined(LITE)
PLIST_SUB+=		${x:U}="@comment $x not installed"
CONFIGURE_ARGS+=	--enable-$x=no
.else
PLIST_SUB+=		${x:U}=bin/$x
MAN1+=			$x.1
.endif
.endfor

.if !defined(WITHOUT_X11)
USE_X_PREFIX=	yes
.endif

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_X11)
MAN1+=		ethereal.1
PLIST_SUB+=	ETHEREAL=bin/ethereal
.if defined(WITHOUT_GTK2)
USE_GNOME+=	gtk12
CONFIGURE_ARGS+=	--disable-gtk2
.else
USE_GNOME+=	gtk20
.endif
.else
PLIST_SUB+=	ETHEREAL="@comment ethereal not built"
USE_GNOME+=	glib12
CONFIGURE_ARGS+=	--enable-ethereal=no \
			--disable-gtktest \
			--with-gtk-prefix=/nonexistent \
			--disable-gtk2
.endif

USE_LIBTOOL_VER=15
LIBTOOLFILES=	configure wiretap/configure
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

.if ${OSVERSION} >= 400014 && !defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6=yes
.else
CONFIGURE_ARGS+=	--enable-ipv6=no
.endif

.if exists(/usr/include/openssl/crypto.h)
CONFIGURE_ARGS+=	--with-ssl=/usr
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

.if !defined(WITHOUT_SNMP) && !defined(LITE)
LIB_DEPENDS+=	netsnmp.7:${PORTSDIR}/net-mgmt/net-snmp
CONFIGURE_ARGS+=	--with-net-snmp=${LOCALBASE}/bin/net-snmp-config
.else
CONFIGURE_ARGS+=	--enable-snmp=no --with-ucd-snmp=no --with-net-snmp=no
.endif

.if !defined(WITHOUT_ADNS) && !defined(LITE)
LIB_DEPENDS+=	adns.1:${PORTSDIR}/dns/adns
CONFIGURE_ARGS+=	--with-adns=${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=	--with-adns=no
.endif

MAN1+=	tethereal.1
MAN4+=	ethereal-filter.4

.include <bsd.port.post.mk>
