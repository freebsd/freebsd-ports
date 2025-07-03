PORTNAME=	suricata
DISTVERSION=	7.0.10
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	https://www.openinfosecfoundation.org/download/

MAINTAINER=	franco@opnsense.org
COMMENT=	High Performance Network IDS, IPS and Security Monitoring engine
WWW=		https://suricata.io

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	rustc:lang/${RUST_DEFAULT}
LIB_DEPENDS=	libjansson.so:devel/jansson \
		liblz4.so:archivers/liblz4 \
		libnet.so:net/libnet \
		libpcre2-8.so:devel/pcre2 \
		libyaml.so:textproc/libyaml

USES=		autoreconf cpe gmake iconv:translit libtool localbase pathfix \
		pkgconfig shebangfix
SHEBANG_FILES=	python/suricata/sc/suricatasc.py

CPE_VENDOR=	openinfosecfoundation

USE_LDCONFIG=	yes
USE_RC_SUBR=	${PORTNAME}

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-gccmarch-native \
			--enable-bundled-htp \
			--enable-gccprotect
MAKE_ENV=		RUSTFLAGS="${RUSTFLAGS} -C linker=${CC:Q} ${LDFLAGS:C/.+/-C link-arg=&/}"

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

CONFLICTS_INSTALL=	libhtp

SUB_FILES=	pkg-message

OPTIONS_DEFINE=		GEOIP IPFW NETMAP NSS PORTS_PCAP PYTHON REDIS TESTS
OPTIONS_DEFINE_amd64=	HYPERSCAN
OPTIONS_DEFAULT=	IPFW NETMAP PYTHON

OPTIONS_RADIO=		SCRIPTS
OPTIONS_RADIO_SCRIPTS=	LUA LUAJIT

OPTIONS_SUB=	yes

GEOIP_DESC=		GeoIP support
HYPERSCAN_DESC=		Hyperscan support
IPFW_DESC=		IPFW and IP Divert support for inline IDP
LUAJIT_DESC=		LuaJIT scripting support
LUA_DESC=		LUA scripting support
NETMAP_DESC=		Netmap support for inline IDP
NSS_DESC=		File checksums and SSL/TLS fingerprinting
PORTS_PCAP_DESC=	Use libpcap from ports
PYTHON_DESC=		Python-based update and control utilities
REDIS_DESC=		Redis output support
SCRIPTS_DESC=		Scripting
TESTS_DESC=		Unit tests in suricata binary

GEOIP_LIB_DEPENDS=	libmaxminddb.so:net/libmaxminddb
GEOIP_CONFIGURE_ON=	--enable-geoip

HYPERSCAN_LIB_DEPENDS=	libhs.so:devel/hyperscan

IPFW_CONFIGURE_ON=	--enable-ipfw

LUAJIT_USES=		luajit
LUAJIT_CONFIGURE_ON=	--enable-luajit

LUA_USES=		lua:51
LUA_CONFIGURE_ON=	--enable-lua

NETMAP_CONFIGURE_ENABLE=	netmap

NSS_LIB_DEPENDS=	libnspr4.so:devel/nspr \
			libnss3.so:security/nss
NSS_CONFIGURE_OFF=	--disable-nspr \
			--disable-nss

PORTS_PCAP_LIB_DEPENDS=	libpcap.so.1:net/libpcap

PYTHON_BUILD_DEPENDS=		${PYTHON_RUN_DEPENDS}
PYTHON_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR}
PYTHON_USES=			python
PYTHON_CONFIGURE_ENABLE=	python

REDIS_LIB_DEPENDS=	libevent_pthreads.so:devel/libevent \
			libhiredis.so:databases/hiredis
REDIS_CONFIGURE_ON=	--enable-hiredis
TESTS_CONFIGURE_ENABLE=	unittests

pre-patch:
	@${CP} ${FILESDIR}/ax_check_compile_flag.m4 ${WRKSRC}/m4

post-patch:
# Disable vendor checksums
	@${REINPLACE_CMD} 's,"files":{[^}]*},"files":{},' \
		${WRKSRC}/rust/vendor/*/.cargo-checksum.json

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
	-d /usr/local/lib/suricata/python -f lib/suricata/python)
.for f in disable.conf drop.conf enable.conf modify.conf threshold.in update.yaml
	${INSTALL_DATA} ${WRKSRC}/suricata-update/suricata/update/configs/${f} \
	${STAGEDIR}${PREFIX}/lib/suricata/python/suricata/update/configs
.endfor

.include <bsd.port.mk>
