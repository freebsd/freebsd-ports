# Created by: Patrick Tracanelli <eksffa@freebsdbrasil.com.br>
# $FreeBSD$

PORTNAME=	suricata
DISTVERSION=	5.0.1
CATEGORIES=	security
MASTER_SITES=	https://www.openinfosecfoundation.org/download/

MAINTAINER=	franco@opnsense.org
COMMENT=	High Performance Network IDS, IPS and Security Monitoring engine

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	rustc:lang/${RUST_DEFAULT}

LIB_DEPENDS=	libpcre.so:devel/pcre \
		libnet.so:net/libnet \
		liblz4.so:archivers/liblz4 \
		libyaml.so:textproc/libyaml

USES=		autoreconf cpe gmake iconv:translit libtool pathfix pkgconfig

CONFLICTS_INSTALL=	libhtp suricata5

USE_LDCONFIG=	yes
USE_RC_SUBR=	${PORTNAME}
PLIST_SUB=	PORTVERSION=${DISTVERSION:C/-/_/g}

GNU_CONFIGURE=	yes

CPE_VENDOR=	openinfosecfoundation

INSTALL_TARGET=		install-strip
TEST_TARGET=		check

OPTIONS_DEFINE=		GEOIP IPFW JSON NETMAP NSS PORTS_PCAP PRELUDE \
			PYTHON REDIS TESTS
OPTIONS_DEFINE_amd64=	HYPERSCAN
OPTIONS_DEFAULT=	IPFW JSON NETMAP PYTHON
OPTIONS_SUB=		yes

OPTIONS_RADIO=		SCRIPTS
OPTIONS_RADIO_SCRIPTS=	LUA LUAJIT

GEOIP_DESC=		GeoIP support
HYPERSCAN_DESC=		Hyperscan support
IPFW_DESC=		IPFW and IP Divert support for inline IDP
JSON_DESC=		JSON output support
LUAJIT_DESC=		LuaJIT scripting support
LUA_DESC=		LUA scripting support
NETMAP_DESC=		Netmap support for inline IDP
NSS_DESC=		File checksums and SSL/TLS fingerprinting
PORTS_PCAP_DESC=	Use libpcap from ports
PRELUDE_DESC=		Prelude support for NIDS alerts
PYTHON_DESC=		Python-based update and control utilities
REDIS_DESC=		Redis output support
SCRIPTS_DESC=		Scripting
TESTS_DESC=		Unit tests in suricata binary

GEOIP_LIB_DEPENDS=		libmaxminddb.so:net/libmaxminddb
GEOIP_CONFIGURE_ON=		--enable-geoip

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
NSS_CONFIGURE_OFF=		--disable-nss --disable-nspr
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

PYTHON_USES=			python
PYTHON_USE=			PYTHON=py3kplist
PYTHON_CONFIGURE_ENABLE=	python
PYTHON_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR}
PYTHON_BUILD_DEPENDS=		${PYTHON_RUN_DEPENDS}

REDIS_LIB_DEPENDS=		libhiredis.so:databases/hiredis
REDIS_CONFIGURE_ON=		--enable-hiredis \
				--with-libhiredis-includes=${LOCALBASE}/include \
				--with-libhiredis-libraries=${LOCALBASE}/lib

TESTS_CONFIGURE_ENABLE=		unittests

SUB_FILES=	pkg-message

CONFIGURE_ARGS+=--enable-gccprotect \
		--enable-bundled-htp \
		--with-libpcre-includes=${LOCALBASE}/include \
		--with-libpcre-libraries=${LOCALBASE}/lib \
		--with-libyaml-includes=${LOCALBASE}/include \
		--with-libyaml-libraries=${LOCALBASE}/lib \
		--with-libnet-includes=${LOCALBASE}/include \
		--with-libnet-libraries=${LOCALBASE}/lib \
		--with-libhtp-includes=${LOCALBASE}/include/ \
		--with-libhtp-libraries=${LOCALBASE}/lib \
	        --disable-gccmarch-native

pre-patch:
	@${CP} ${FILESDIR}/ax_check_compile_flag.m4 ${WRKSRC}/m4

post-patch-PYTHON-on:
	@${REINPLACE_CMD} -e "/AC_PATH_PROGS.*HAVE_PYTHON/ s/python[^,]*,/${PYTHON_VERSION},/g" \
		${WRKSRC}/configure.ac

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR} ${STAGEDIR}/var/log/suricata
.for f in classification.config reference.config
	@${MV} ${STAGEDIR}${DATADIR}/${f} ${STAGEDIR}${ETCDIR}/${f}.sample
.endfor
.for f in suricata.yaml threshold.config
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${ETCDIR}/${f}.sample
.endfor

post-install-PYTHON-on:
	(cd ${STAGEDIR}${PREFIX} \
	&& ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
	-d ${PYTHONPREFIX_SITELIBDIR} -f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;})

.include <bsd.port.mk>
