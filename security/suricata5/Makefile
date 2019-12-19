# Created by: Muhammad Moinur Rahman <bofh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	suricata
DISTVERSION=	5.0.0-rc1
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	https://www.openinfosecfoundation.org/download/
PKGNAMESUFFIX=	5

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	High Performance Network IDS, IPS and Security Monitoring engine(v5)

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	rustc:lang/${RUST_DEFAULT} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR}
LIB_DEPENDS=	libjansson.so:devel/jansson \
		liblz4.so:archivers/liblz4 \
		libnet.so:net/libnet \
		libpcre.so:devel/pcre \
		libyaml.so:textproc/libyaml
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR}

USES=		autoreconf cpe libtool pkgconfig python
USE_LDCONFIG=	yes
USE_PYTHON=	py3kplist
USE_RC_SUBR=	${PORTNAME}

CONFLICTS_INSTALL=libhtp

GNU_CONFIGURE=	yes

CPE_VENDOR=	openinfosecfoundation

INSTALL_TARGET=	install-strip
TEST_TARGET=		check

OPTIONS_DEFINE=		GEOIP IPFW NSS PORTS_PCAP PRELUDE REDIS TESTS
OPTIONS_DEFINE_amd64=	HYPERSCAN
OPTIONS_DEFAULT=	IPFW
OPTIONS_SUB=		yes

OPTIONS_RADIO=		SCRIPTS
OPTIONS_RADIO_SCRIPTS=	LUA LUAJIT

SCRIPTS_DESC=		Scripting
HYPERSCAN_DESC=		Hyperscan support
IPFW_DESC=		IPFW and IP Divert support for inline IDP
LUAJIT_DESC=		LuaJIT scripting support
LUA_DESC=		LUA scripting support
NSS_DESC=		File checksums and SSL/TLS fingerprinting
PORTS_PCAP_DESC=	Use libpcap from ports
PRELUDE_DESC=		Prelude support for NIDS alerts
REDIS_DESC=		Redis output support
TESTS_DESC=		Unit tests in suricata binary

GEOIP_LIB_DEPENDS=	libmaxminddb.so:net/libmaxminddb
GEOIP_CONFIGURE_ON=	--enable-geoip
HYPERSCAN_LIB_DEPENDS=	libhs.so:devel/hyperscan
IPFW_CONFIGURE_ON=	--enable-ipfw
LUA_USES=		lua:51
LUA_CONFIGURE_ENABLE=	lua
LUAJIT_LIB_DEPENDS=	libluajit-5.1.so:lang/luajit
LUAJIT_CONFIGURE_ENABLE=luajit
NSS_LIB_DEPENDS=		libnss3.so:security/nss \
				libnspr4.so:devel/nspr
NSS_CONFIGURE_ENABLE=		nss nspr
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
REDIS_LIB_DEPENDS=		libhiredis.so:databases/hiredis
REDIS_CONFIGURE_ENABLE=		hiredis
TESTS_CONFIGURE_ENABLE=		unittests

SUB_FILES=	pkg-message

CONFIGURE_ARGS+=--enable-gccprotect \
		--enable-bundled-htp \
	        --disable-gccmarch-native \
		--enable-netmap \
		--disable-af-packet \
		--disable-nflog \
		--disable-nfqueue \
		--disable-pfring \
		--disable-windivert \
		--disable-ebpf-build \
		--disable-ebpf

CONFIG_DIR?=	${ETCDIR}
CONFIG_FILES=	suricata.yaml classification.config reference.config threshold.config
LOGS_DIR?=	/var/log/${PORTNAME}

pre-patch:
	@${CP} ${FILESDIR}/ax_check_compile_flag.m4 ${WRKSRC}/m4

post-patch:
	@${REINPLACE_CMD} -e "/AC_PATH_PROGS.*HAVE_PYTHON/ s/python[^,]*,/${PYTHON_VERSION},/g" \
		${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e "s|GeoIP.h|maxminddb.h|g" \
		${WRKSRC}/configure.ac

post-install:
	@${MKDIR} ${STAGEDIR}${CONFIG_DIR}
	@${MKDIR} ${STAGEDIR}${LOGS_DIR}
.for f in ${CONFIG_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${CONFIG_DIR}/${f}.sample
.endfor
	(cd ${STAGEDIR}${PREFIX} \
	&& ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
	-d ${PYTHONPREFIX_SITELIBDIR} -f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;})

.include <bsd.port.mk>
