# Created by: Bill Fumerola <billf@chc-chimes.com>
# $FreeBSD$

PORTNAME?=	wireshark
PORTVERSION=	2.0.4
PORTREVISION?=	0
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

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS?=	wireshark-qt5-[0-9]*

DATADIR_NAME=	wireshark
DATADIR=	${PREFIX}/share/${DATADIR_NAME}

GNU_CONFIGURE=	yes
USES=		alias cpe gmake libtool perl5 pkgconfig python:build tar:bzip2
USE_PERL5=	build
USE_GNOME=	glib20
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--program-transform-name="" \
			--with-ssl=${OPENSSLBASE}
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

CFLAGS+=	-funit-at-a-time
LIBS+=		-L${LOCALBASE}/lib
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

.for x in capinfos editcap mergecap rawshark text2pcap dftest randpkt \
    reordercap captype androiddump
.if defined(LITE)
PKGNAMESUFFIX=		-lite
PLIST_SUB+=		${x:tu}="@comment $x not installed" \
			${x:tu}_MAN="@comment $x not installed "
CONFIGURE_ARGS+=	--enable-$x=no
OPTIONS_EXCLUDE+=	RTP SNMP GEOIP LUA ADNS CARES
.else
PLIST_SUB+=		${x:tu}=bin/$x \
			${x:tu}_MAN=""
.endif
.endfor

OPTIONS_DEFINE=		RTP SNMP IPV6 GEOIP LUA DECRYPT

OPTIONS_RADIO=		ASYNCDNS GUI
OPTIONS_SINGLE=		KERBEROS

OPTIONS_RADIO_ASYNCDNS=	ADNS CARES
OPTIONS_RADIO_GUI=	GTK2 GTK3 QT5
OPTIONS_SINGLE_KERBEROS=KRB_BASE KRB_HEIMDAL KRB_MIT KRB_NONE

OPTIONS_DEFAULT?=	SNMP ADNS IPV6 GEOIP KRB_BASE GTK3

RTP_DESC=		Enable support for playing back RTP streams
DECRYPT_DESC=		Decryption support for SSL and IPSec
ASYNCDNS_DESC=		Asynchronous DNS lookup support
ADNS_DESC=		Asynchronous DNS resolution via GNU adns
KERBEROS_DESC=		Kerberos dissection support
KRB_BASE_DESC=		Kerberos support via base system
KRB_HEIMDAL_DESC=	Kerberos support via security/heimdal
KRB_MIT_DESC=		Kerberos support via security/krb5
KRB_NONE_DESC=		Disable Kerberos support

GTK2_USE=	GNOME=gtk20
GTK3_USE=	GNOME=gtk30
QT5_USE=	QT5=core,gui,widgets,printsupport,buildtools_build

LUA_USES=		lua:5[1-2]
KRB_BASE_USES=		gssapi
KRB_HEIMDAL_USES=	gssapi:heimdal
KRB_MIT_USES=		gssapi:mit

RTP_LIB_DEPENDS=	libportaudio.so:audio/portaudio
SNMP_LIB_DEPENDS=	libsmi.so:net-mgmt/libsmi
ADNS_LIB_DEPENDS=	libadns.so:dns/adns
CARES_LIB_DEPENDS=	libcares.so:dns/c-ares
GEOIP_LIB_DEPENDS=	libGeoIP.so:net/GeoIP
DECRYPT_LIB_DEPENDS=	libgnutls.so:security/gnutls \
    			libgcrypt.so:security/libgcrypt

IPV6_CONFIGURE_ENABLE=	ipv6

KRB_NONE_CONFIGURE_ON=	--without-krb5
KRB_NONE_CONFIGURE_OFF=	--with-krb5
KRB_NONE_CONFIGURE_ENV_OFF=	KRB5_CONFIG=${KRB5CONFIG}

GTK2_CONFIGURE_WITH=	gtk2
GTK3_CONFIGURE_WITH=	gtk3
QT5_CONFIGURE_WITH=	qt
LUA_CONFIGURE_WITH=	lua
RTP_CONFIGURE_WITH=	portaudio
SNMP_CONFIGURE_WITH=	libsmi
ADNS_CONFIGURE_WITH=	adns
CARES_CONFIGURE_WITH=	c-ares
GEOIP_CONFIGURE_WITH=	geoip
DECRYPT_CONFIGURE_WITH=	gnutls gcrypt

LUA_CPPFLAGS=		-I${LUA_INCDIR}

QT5_MAKE_ENV=		PATH="${PATH}:${QT_BINDIR}"
QT5_VARS=		PKGNAMESUFFIX=-qt5
QT5_PLIST_SUB=		GUI_GTK="@comment "

GTK2_PLIST_SUB=		GUI_GTK=""
GTK3_PLIST_SUB=		GUI_GTK=""

OPTIONS_SUB=		LUA

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MGTK2) && empty(PORT_OPTIONS:MGTK3) && \
    empty(PORT_OPTIONS:MQT5)
CONFIGURE_ARGS+=	--disable-wireshark
PLIST_SUB+=		GUI="@comment "
.else
USES+=			desktop-file-utils shared-mime-info
INSTALLS_ICONS=		yes
PLIST_SUB+=		GUI=""
.endif

.if ${PORT_OPTIONS:MKRB_BASE} && exists(${LOCALBASE}/include/krb5.h)
IGNORE=			cannot build with base Kerberos if krb5 port is installed. \
			Use ``make config'' to choose a different option
.endif

.if empty(PORT_OPTIONS:MGTK2) && empty(PORT_OPTIONS:MGTK3) && \
	${PORT_OPTIONS:MRTP}
IGNORE=			the RTP support requires GTK+ frontend
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|llua|llua-${LUA_VER}|g ; \
		s|-DQT_GUI_LIB|-DQT_GUI_LIB $$CPPFLAGS| ' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/usr/share/applications|${DESKTOPDIR}|g ; \
		s|/usr/share|${LOCALBASE}/share|g ; \
		s|{mime/packages,applications}|mime/packages| ; \
		s|{apps,mimetypes}|apps $$(DESTDIR)${LOCALBASE}/share/icons/hicolor/$$$${size}x$$$${size}/mimetypes|' \
		${WRKSRC}/Makefile.in

.if ${PORT_OPTIONS:MGTK2} || ${PORT_OPTIONS:MGTK3}
post-install:
	${MV} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-gtk \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
.endif

.include <bsd.port.mk>
