PORTNAME=	wireshark
DISTVERSION=	4.4.8
CATEGORIES=	net
MASTER_SITES=	https://1.na.dl.wireshark.org/src/ \
		https://1.eu.dl.wireshark.org/src/ \
		https://1.as.dl.wireshark.org/src/ \
		https://2.na.dl.wireshark.org/src/ \
		http://ftp.uni-kl.de/pub/wireshark/src/ \
		http://ftp.yz.yamagata-u.ac.jp/pub/network/security/wireshark/src/ \
		https://wireshark.marwan.ma/download/src/ \
		https://www.wireshark.org/download/src/

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	Powerful network analyzer/capture tool
WWW=		https://www.wireshark.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpcre2-8.so:devel/pcre2 \
		libgcrypt.so:security/libgcrypt \
		liblz4.so:archivers/liblz4 \
		libnghttp2.so:www/libnghttp2 \
		libnghttp3.so:www/libnghttp3 \
		libbrotlidec.so:archivers/brotli \
		libsnappy.so:archivers/snappy \
		libcares.so:dns/c-ares \
		libzstd.so:archivers/zstd \
		libspeexdsp.so:audio/speexdsp

FLAVORS=	default nox11
FLAVOR?=	${FLAVORS:[1]}
nox11_PKGNAMESUFFIX=	-nox11

USES=		cmake compiler:c++11-lang cpe gettext-runtime:build gnome \
		localbase pathfix perl5 pkgconfig python ssl tar:xz
USE_GNOME=	glib20 libxml2
USE_PERL5=	build
USE_LDCONFIG=	yes

CONFLICTS_INSTALL=	wireshark-lite tshark tshark-lite

CMAKE_OFF=	ENABLE_ILBC ENABLE_MINIZIP ENABLE_SBC ENABLE_SINSP \
		ENABLE_AMRNB ENABLE_MINIZIPNG ENABLE_ZLIBNG
CMAKE_ARGS=	-DCMAKE_DISABLE_FIND_PACKAGE_DOXYGEN:BOOL=True \
		-DCMAKE_DISABLE_FIND_PACKAGE_Git:BOOL=True

OPTIONS_DEFINE=		ANDROIDDUMP DEVELOPMENT DOCS GNUTLS GUI LIBSSH LTO LUA \
			MANPAGES MAXMIND RTP SNMP
.if ${FLAVOR} == nox11
COMMENT+=		(without GUI)
OPTIONS_EXCLUDE=	GUI RTP
.endif

OPTIONS_DEFAULT=	ANDROIDDUMP DEVELOPMENT GNUTLS GSSAPI_BASE GUI MANPAGES MAXMIND \
			RTP SNMP
OPTIONS_DEFAULT_aarch64=LTO
OPTIONS_DEFAULT_amd64=	LTO
OPTIONS_SINGLE=		GSSAPI
OPTIONS_SINGLE_GSSAPI=	GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT GSSAPI_NONE
OPTIONS_SUB=		yes

ANDROIDDUMP_DESC=	Build androiddump extcap tool
DEVELOPMENT_DESC=	Install development headers and support files
GNUTLS_DESC=		Enable crypto support for SSL and IPSec via GnuTLS
GUI_DESC=		Enable Qt 6 based Wireshark GUI
LIBSSH_DESC=		Enable libssh support (req by cisco/ssh/wifidump)
MAXMIND_DESC=		Enable MaxMindDB-based GeoIP geolocation support
RTP_DESC=		Enable codec support for RTP streams (implies GUI)

ANDROIDDUMP_CMAKE_BOOL=	BUILD_androiddump

DOCS_IMPLIES=		MANPAGES

GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_CMAKE_BOOL=	ENABLE_GNUTLS

GSSAPI_BASE_USES=	gssapi
GSSAPI_HEIMDAL_USES=	gssapi:heimdal
GSSAPI_MIT_USES=	gssapi:mit
GSSAPI_NONE_CONFIGURE_ENV_OFF=	KRB5_CONFIG=${KRB5CONFIG}
GSSAPI_NONE_CMAKE_BOOL=	ENABLE_KERBEROS

GUI_USES=		desktop-file-utils shared-mime-info qt:6
GUI_USE=		qt=5compat,base,multimedia,tools
GUI_CONFIGURE_ENV=	PATH="${PATH}:${QT_BINDIR}"
GUI_MAKE_ENV=		PATH="${PATH}:${QT_BINDIR}"
GUI_CMAKE_BOOL=		BUILD_wireshark

LIBSSH_LIB_DEPENDS=	libssh.so:security/libssh
LIBSSH_CMAKE_BOOL=	BUILD_ciscodump BUILD_sshdump BUILD_wifidump

LTO_CMAKE_BOOL=		ENABLE_LTO

LUA_USES=		lua:53-54
LUA_CPPFLAGS=		-I${LUA_INCDIR}
LUA_CMAKE_BOOL=		ENABLE_LUA

MANPAGES_BUILD_DEPENDS=	asciidoctor:textproc/rubygem-asciidoctor
MANPAGES_CMAKE_OFF=	-DCMAKE_DISABLE_FIND_PACKAGE_Asciidoctor:BOOL=True

MAXMIND_LIB_DEPENDS=	libmaxminddb.so:net/libmaxminddb
MAXMIND_CMAKE_BOOL=	BUILD_mmdbresolve

RTP_LIB_DEPENDS=	libbcg729.so:audio/bcg729 \
			libopus.so:audio/opus \
			libspandsp.so:comms/spandsp
RTP_CMAKE_BOOL=		ENABLE_BCG729 ENABLE_OPUS ENABLE_SPANDSP
RTP_IMPLIES=		GUI

SNMP_LIB_DEPENDS=	libsmi.so:net-mgmt/libsmi
SNMP_CMAKE_BOOL=	ENABLE_SMI

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGSSAPI_BASE} && exists(${LOCALBASE}/include/krb5.h)
IGNORE=			cannot build with base Kerberos if krb5 port is installed. \
			Use ``make config'' to choose a different option
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/applications|${DESKTOPDIR}|g ; \
		s|/usr/share|${LOCALBASE}/share|g' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|lua$${LUA_INC_SUFFIX}|lua-${LUA_VER}|g' \
	    	${WRKSRC}/cmake/modules/FindLua.cmake

post-install-DEVELOPMENT-on:
	cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${FAKEROOT} ${CMAKE_BIN} ${CMAKE_ARGS} -DCOMPONENT=Development -P cmake_install.cmake

.include <bsd.port.mk>
