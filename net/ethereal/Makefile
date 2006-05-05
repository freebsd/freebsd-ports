# New ports collection makefile for:   ethereal
# Date created:        10 August 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $FreeBSD$
#

PORTNAME=	ethereal
PORTVERSION=	0.99.0
PORTREVISION?=	2
CATEGORIES=	net ipv6
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.ethereal.com/pub/ethereal/all-versions/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	marcus@FreeBSD.org
COMMENT?=	A powerful network analyzer/capture tool

USE_PERL5_BUILD=yes
USE_PYTHON_BUILD=yes
USE_ICONV=	yes
#USE_BZIP2=	yes
USE_GCC=	3.4+
USE_GNOME=	gnometarget
WANT_GNOME=	yes
USE_OPENSSL=	yes
CONFIGURE_ENV=	MIBDIRS="/dev/null"
CONFIGURE_ARGS+=	--program-transform-name="" \
			--with-ssl=/usr
MAKE_ENV=	MIBDIRS="/dev/null"
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

.for x in dftest randpkt
.if defined(LITE)
PLIST_SUB+=	${x:U}="@comment $x not installed"
CONFIGURE_ARGS+=	--enable-$x=no
.else
PLIST_SUB+=	${x:U}=bin/$x
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

GNU_CONFIGURE=	yes
LIBTOOLFILES=	configure wiretap/configure
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

.if ${OSVERSION} >= 400014 && !defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6=yes
.else
CONFIGURE_ARGS+=	--enable-ipv6=no
.endif

.if ${OSVERSION} < 504103
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-capture_loop.h
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
LIB_DEPENDS+=	netsnmp.9:${PORTSDIR}/net-mgmt/net-snmp
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

.if exists(${LOCALBASE}/lib/libgnutls.so) || defined(WITH_GNUTLS)
LIB_DEPENDS+=	gnutls.15:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=	--with-libgnutls-prefix=${LOCALBASE}
.endif

MAN1+=	dumpcap.1 tethereal.1
MAN4+=	ethereal-filter.4

.include <bsd.port.post.mk>
