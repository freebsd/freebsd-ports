# Created by: Bill Fumerola <billf@chc-chimes.com>
# $FreeBSD$

PORTNAME?=	wireshark
PORTVERSION=	3.2.2
PORTREVISION?=	0
CATEGORIES=	net
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

CONFLICTS_INSTALL?=	wireshark-lite-[0-9]* tshark-[0-9]* tshark-lite-[0-9]*

DATADIR_NAME=	wireshark
DATADIR=	${PREFIX}/share/${DATADIR_NAME}

USES=		alias cmake compiler:c++11-lang cpe gettext-runtime gnome \
		libtool localbase pathfix perl5 pkgconfig python:3.4+ ssl \
		tar:xz
USE_PERL5=	build
USE_GNOME=	glib20 libxml2
USE_LDCONFIG=	yes

LIB_DEPENDS+=	libgpg-error.so:security/libgpg-error \
		libgcrypt.so:security/libgcrypt \
		liblz4.so:archivers/liblz4 \
		libnghttp2.so:www/libnghttp2 \
		libsnappy.so:archivers/snappy

#CFLAGS+=	-funit-at-a-time
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

.for x in capinfos editcap mergecap rawshark text2pcap dftest randpkt \
    reordercap captype randpktdump udpdump sharkd
.if defined(LITE)
PKGNAMESUFFIX=		-lite
PLIST_SUB+=		${x:tu}="@comment $x not installed" \
			${x:tu}_LIB="@comment $x not installed " \
			${x:tu}_MAN="@comment $x not installed "
CMAKE_ARGS+=		-DBUILD_$x=OFF
EXTRA_PATCHES=		${FILESDIR}/extra-patch-doc_CMakeLists.txt
OPTIONS_EXCLUDE+=	RTP SNMP LUA CARES ANDROIDDUMP CISCODUMP SSHDUMP
.else
PLIST_SUB+=		${x:tu}=bin/$x \
			${x:tu}_MAN="" \
			${x:tu}_LIB=""
.endif
.endfor

OPTIONS_DEFINE=		GUI RTP SNMP MAXMIND LUA DECRYPT ANDROIDDUMP CARES SSHDUMP CISCODUMP

OPTIONS_SINGLE=		GSSAPI

OPTIONS_SINGLE_GSSAPI=GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT GSSAPI_NONE

OPTIONS_DEFAULT?=	GUI SNMP MAXMIND GSSAPI_BASE DECRYPT

GUI_DESC=		Enable Qt 5 based Wireshark GUI
RTP_DESC=		Enable support for playing back RTP streams
DECRYPT_DESC=		Decryption support for SSL and IPSec
ANDROIDDUMP_DESC=	Build androiddump extcap tool
MAXMIND_DESC=		Enable MaxMindDB-based GeoIP geolocation support
CARES_DESC=		Enable support for asynchronous DNS via c-ares
GSSAPI_DESC=		Kerberos dissection support
GSSAPI_BASE_DESC=		Kerberos support via base system
GSSAPI_HEIMDAL_DESC=	Kerberos support via security/heimdal
GSSAPI_MIT_DESC=		Kerberos support via security/krb5
GSSAPI_NONE_DESC=		Disable Kerberos support
SSHDUMP_DESC=		Build sshdump extcap tool
CISCODUMP_DESC=		Build ciscodump extcap tool

GUI_USES=		qt:5
GUI_USE=	qt=core,gui,multimedia,widgets,printsupport,svg,buildtools_build,linguisttools_build,qmake_build

LUA_USES=		lua:5[1-2]
GSSAPI_BASE_USES=		gssapi
GSSAPI_HEIMDAL_USES=	gssapi:heimdal
GSSAPI_MIT_USES=		gssapi:mit

RTP_LIB_DEPENDS=	libspandsp.so:comms/spandsp
RTP_CPPFLAGS=		-I${LOCALBASE}/include
MAXMIND_LIB_DEPENDS=	libmaxminddb.so:net/libmaxminddb
SNMP_LIB_DEPENDS=	libsmi.so:net-mgmt/libsmi
CARES_LIB_DEPENDS=	libcares.so:dns/c-ares
DECRYPT_LIB_DEPENDS=	libgnutls.so:security/gnutls \
			libgcrypt.so:security/libgcrypt
SSHDUMP_LIB_DEPENDS=	libssh.so:security/libssh
CISCODUMP_LIB_DEPENDS=	libssh.so:security/libssh

GSSAPI_NONE_CMAKE_ON=	-DENABLE_KERBEROS=OFF
GSSAPI_NONE_CMAKE_OFF=	-DENABLE_KERBEROS=ON
GSSAPI_NONE_CONFIGURE_ENV_OFF=	KRB5_CONFIG=${KRB5CONFIG}

LUA_CMAKE_ON=	-DENABLE_LUA=ON
LUA_CMAKE_OFF=	-DENABLE_LUA=OFF
RTP_CMAKE_ON=	-DENABLE_SPANDSP=ON
RTP_CMAKE_OFF=	-DENABLE_SPANDSP=OFF
SNMP_CMAKE_ON=	-DENABLE_SMI=ON
SNMP_CMAKE_OFF=	-DENABLE_SMI=OFF
CARES_CMAKE_ON=	-DENABLE_CARES=ON
CARES_CMAKE_OFF=	-DENABLE_CARES=OFF
DECRYPT_CMAKE_ON=	-DENABLE_GNUTLS=ON
DECRYPT_CMAKE_OFF=	-DENABLE_GNUTLS=OFF
ANDROIDDUMP_CMAKE_ON=-DBUILD_androiddump=ON
ANDROIDDUMP_CMAKE_OFF=-DBUILD_androiddump=OFF
SSHDUMP_CMAKE_ON=-DBUILD_sshdump=ON
SSHDUMP_CMAKE_OFF=-DBUILD_sshdump=OFF
CISCODUMP_CMAKE_ON=-DBUILD_ciscodump=ON
CISCODUMP_CMAKE_OFF=-DBUILD_ciscodump=OFF

LUA_CPPFLAGS=		-I${LUA_INCDIR}

GUI_CONFIGURE_ENV=	PATH="${PATH}:${QT_BINDIR}"
GUI_MAKE_ENV=		PATH="${PATH}:${QT_BINDIR}"

OPTIONS_SUB=		yes

.if defined(LITE)
CMAKE_ARGS+=	-DBUILD_androiddump=OFF \
		-DBUILD_sshdump=OFF \
		-DBUILD_ciscodump=OFF
PLIST_SUB+=	ANDROIDDUMP_LIB="@comment " \
		ANDROIDDUMP_MAN="@comment " \
		SSHDUMP_LIB="@comment " \
		SSHDUMP_MAN="@comment " \
		CISCODUMP_LIB="@comment " \
		CISCODUMP_MAN="@comment "
.endif

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MMAXMIND)
CMAKE_ARGS+=	-DBUILD_mmdbresolve=OFF
.else
CMAKE_ARGS+=	-DBUILD_mmdbresolve=ON
.endif

.if empty(PORT_OPTIONS:MGUI)
CMAKE_ARGS+=	-DBUILD_wireshark=OFF
PLIST_SUB+=	GUI="@comment "
.else
USES+=		desktop-file-utils shared-mime-info
INSTALLS_ICONS=	yes
PLIST_SUB+=	GUI=""
.endif

.if !defined(LITE)
.if ${PORT_OPTIONS:MANDROIDDUMP}
PLIST_SUB+=	ANDROIDDUMP_LIB="" \
		ANDROIDDUMP_MAN=""
.else
PLIST_SUB+=	ANDROIDDUMP_LIB="@comment " \
		ANDROIDDUMP_MAN="@comment "
.endif
.if ${PORT_OPTIONS:MSSHDUMP}
PLIST_SUB+=	SSHDUMP_LIB="" \
		SSHDUMP_MAN=""
.else
PLIST_SUB+=	SSHDUMP_LIB="@comment " \
		SSHDUMP_MAN="@comment "
.endif
.if ${PORT_OPTIONS:MCISCODUMP}
PLIST_SUB+=	CISCODUMP_LIB="" \
		CISCODUMP_MAN=""
.else
PLIST_SUB+=	CISCODUMP_LIB="@comment " \
		CISCODUMP_MAN="@comment "
.endif
.endif

.if ${PORT_OPTIONS:MGSSAPI_BASE} && exists(${LOCALBASE}/include/krb5.h)
IGNORE=			cannot build with base Kerberos if krb5 port is installed. \
			Use ``make config'' to choose a different option
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/applications|${DESKTOPDIR}|g ; \
		s|/usr/share|${LOCALBASE}/share|g' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|lua$${LUA_INC_SUFFIX}|lua-${LUA_VER}|g' \
	    	${WRKSRC}/cmake/modules/FindLUA.cmake

.include <bsd.port.mk>
