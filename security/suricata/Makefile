# Created by: Patrick Tracanelli <eksffa@freebsdbrasil.com.br>
# $FreeBSD$

PORTNAME=	suricata
PORTVERSION=	4.0.1
CATEGORIES=	security
MASTER_SITES=	http://www.openinfosecfoundation.org/download/

MAINTAINER=	franco@opnsense.org
COMMENT=	High Performance Network IDS, IPS and Security Monitoring engine

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpcre.so:devel/pcre \
		libnet.so:net/libnet \
		libyaml.so:textproc/libyaml

USES=		autoreconf cpe gmake libtool pathfix pkgconfig
USE_LDCONFIG=	yes
USE_RC_SUBR=	${PORTNAME}

GNU_CONFIGURE=	yes

CPE_VENDOR=	openinfosecfoundation

INSTALL_TARGET=		install-strip
TEST_TARGET=		check

OPTIONS_DEFINE=		GEOIP HTP_PORT IPFW JSON NETMAP NSS PORTS_PCAP PRELUDE \
			REDIS SC TESTS
OPTIONS_DEFINE_amd64=	HYPERSCAN
OPTIONS_DEFAULT=	HTP_PORT IPFW JSON NETMAP PRELUDE
OPTIONS_SUB=		yes

OPTIONS_RADIO=		SCRIPTS
OPTIONS_RADIO_SCRIPTS=	LUA LUAJIT

SCRIPTS_DESC=		Scripting

GEOIP_DESC=		GeoIP support
HYPERSCAN_DESC=		Hyperscan support
HTP_PORT_DESC=		Use libhtp from ports
IPFW_DESC=		IPFW and IP Divert support for inline IDP
JSON_DESC=		JSON output support
LUA_DESC=		LUA scripting support
LUAJIT_DESC=		LuaJIT scripting support
NETMAP_DESC=		Netmap support for inline IDP
NSS_DESC=		File checksums and SSL/TLS fingerprinting
PORTS_PCAP_DESC=	Use libpcap from ports
PRELUDE_DESC=		Prelude support for NIDS alerts
REDIS_DESC=		Redis output support
SC_DESC=		Suricata socket client (suricatasc)
TESTS_DESC=		Unit tests in suricata binary

GEOIP_LIB_DEPENDS=		libGeoIP.so:net/GeoIP
GEOIP_CONFIGURE_ON=		--enable-geoip

HTP_PORT_BUILD_DEPENDS=		libhtp>=0.5.24:devel/libhtp
HTP_PORT_LIB_DEPENDS=		libhtp.so:devel/libhtp
HTP_PORT_CONFIGURE_ON=		--enable-non-bundled-htp
HTP_PORT_CONFIGURE_OFF=		--enable-bundled-htp
HTP_PORT_CONFLICTS_INSTALL_OFF=	libhtp
HTP_PORT_USES_OFF=		iconv:translit

HYPERSCAN_LIB_DEPENDS=		libhs.so:devel/hyperscan
HYPERSCAN_CONFIGURE_ON=		--with-libhs-includes=${LOCALBASE}/include \
				--with-libhs-libraries=${LOCALBASE}/lib

IPFW_CONFIGURE_ON=		--enable-ipfw

JSON_LIB_DEPENDS=		libjansson.so:devel/jansson
JSON_CONFIGURE_ON=		--with-libjansson-includes=${LOCALBASE}/include \
				--with-libjansson-libraries=${LOCALBASE}/lib

LUA_USES=			lua:51
LUA_CONFIGURE_ON=		--enable-lua \
				--with-liblua-includes=${LUA_INCDIR} \
				--with-liblua-libraries=${LUA_LIBDIR}

LUAJIT_LIB_DEPENDS=		libluajit-5.1.so:lang/luajit
LUAJIT_CONFIGURE_ON=		--enable-luajit

NSS_LIB_DEPENDS=		libnss3.so:security/nss \
				libnspr4.so:devel/nspr
NSS_CONFIGURE_ON=		--with-libnss-includes=${LOCALBASE}/include/nss/nss \
				--with-libnss-libraries=${LOCALBASE}/lib \
				--with-libnspr-libraries=${LOCALBASE}/lib \
				--with-libnspr-includes=${LOCALBASE}/include/nspr

NETMAP_CONFIGURE_ENABLE=	netmap

PORTS_PCAP_LIB_DEPENDS=		libpcap.so.1:net/libpcap
PORTS_PCAP_CONFIGURE_ON=	--with-libpcap-includes=${LOCALBASE}/include \
				--with-libpcap-libraries=${LOCALBASE}/lib
PORTS_PCAP_CONFIGURE_OFF=	--with-libpcap-includes=/usr/include \
				--with-libpcap-libraries=/usr/lib

PRELUDE_LIB_DEPENDS=		libprelude.so:security/libprelude \
				libgnutls.so:security/gnutls \
				libgcrypt.so:security/libgcrypt \
				libgpg-error.so:security/libgpg-error \
				libltdl.so:devel/libltdl
PRELUDE_CONFIGURE_ENABLE=	prelude
PRELUDE_CONFIGURE_ON=		--with-libprelude-prefix=${LOCALBASE}

REDIS_LIB_DEPENDS=		libhiredis.so:databases/hiredis
REDIS_CONFIGURE_ON=		--enable-hiredis \
				--with-libhiredis-includes=${LOCALBASE}/include \
				--with-libhiredis-libraries=${LOCALBASE}/lib

SC_USES=			python:2.7
SC_CONFIGURE_ENABLE=		python

TESTS_CONFIGURE_ENABLE=		unittests

SUB_FILES=	pkg-message

CONFIGURE_ARGS+=--enable-gccprotect \
		--with-libpcre-includes=${LOCALBASE}/include \
		--with-libpcre-libraries=${LOCALBASE}/lib \
		--with-libyaml-includes=${LOCALBASE}/include \
		--with-libyaml-libraries=${LOCALBASE}/lib \
		--with-libnet-includes=${LOCALBASE}/include \
		--with-libnet-libraries=${LOCALBASE}/lib \
		--with-libhtp-includes=${LOCALBASE}/include/ \
		--with-libhtp-libraries=${LOCALBASE}/lib \
	        --disable-gccmarch-native

CONFIG_DIR?=	${ETCDIR}
CONFIG_FILES=	suricata.yaml classification.config reference.config threshold.config
RULES_DIR=	${CONFIG_DIR}/rules
RULES_FILES=	app-layer-events.rules decoder-events.rules dns-events.rules files.rules \
		http-events.rules modbus-events.rules smtp-events.rules stream-events.rules \
		tls-events.rules
LOGS_DIR?=	/var/log/${PORTNAME}

pre-patch:
	${CP} ${FILESDIR}/ax_check_compile_flag.m4 ${WRKSRC}/m4

post-install:
	${MKDIR} ${STAGEDIR}${CONFIG_DIR}
	${MKDIR} ${STAGEDIR}${RULES_DIR}
	${MKDIR} ${STAGEDIR}${LOGS_DIR}
.for f in ${CONFIG_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${CONFIG_DIR}/${f}.sample
.endfor
.for f in ${RULES_FILES}
	${INSTALL_DATA} ${WRKSRC}/rules/${f} ${STAGEDIR}${RULES_DIR}/${f}
.endfor

post-install-SC-on:
	(cd ${STAGEDIR}${PREFIX} \
	&& ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
	-d ${PYTHONPREFIX_SITELIBDIR} -f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;})

.include <bsd.port.mk>
