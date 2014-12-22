# Created by: Patrick Tracanelli <eksffa@freebsdbrasil.com.br>
# $FreeBSD$

PORTNAME=	suricata
PORTVERSION=	2.0.5
CATEGORIES=	security
MASTER_SITES=	http://www.openinfosecfoundation.org/download/ \
		http://mirrors.rit.edu/zi/

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	High Performance Network IDS, IPS and Security Monitoring engine

LICENSE=	GPLv2

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre \
		libnet.so:${PORTSDIR}/net/libnet \
		libyaml.so:${PORTSDIR}/textproc/libyaml

USES=		autoreconf gmake pkgconfig libtool pathfix
USE_LDCONFIG=	yes
USE_RC_SUBR=	${PORTNAME}
GNU_CONFIGURE=	yes

INSTALL_TARGET=		install-strip
PATHFIX_MAKEFILEIN=	Makefile.am

OPTIONS_DEFINE=		GEOIP HTP_PORT IPFW JSON NSS PORTS_PCAP PRELUDE TESTS
OPTIONS_DEFAULT=	HTP_PORT IPFW PRELUDE
OPTIONS_SUB=		yes

GEOIP_DESC=		Enable GeoIP support
HTP_PORT_DESC=		Use libhtp from ports
IPFW_DESC=		Enable IPFW and IP Divert support for inline IDP
JSON_DESC=		Enable JSON output
NSS_DESC=		Enable file checksums and SSL/TLS fingerprinting
PORTS_PCAP_DESC=	Use libpcap from ports
PRELUDE_DESC=		Enable Prelude support for NIDS alerts
TESTS_DESC=		Build Unit Tests

GEOIP_LIB_DEPENDS=		libGeoIP.so:${PORTSDIR}/net/GeoIP
GEOIP_CONFIGURE_ON=		--enable-geoip

HTP_PORT_LIB_DEPENDS=		libhtp.so:${PORTSDIR}/devel/libhtp
HTP_PORT_CONFIGURE_ON=		--enable-non-bundled-htp
HTP_PORT_CONFIGURE_OFF=		--enable-bundled-htp
HTP_PORT_CONFLICTS_INSTALL_OFF=	libhtp-[0-9]* libhtp-suricata
HTP_PORT_USES_OFF=		iconv

IPFW_CONFIGURE_ON=		--enable-ipfw

PORTS_PCAP_LIB_DEPENDS=		libpcap.so:${PORTSDIR}/net/libpcap
PORTS_PCAP_CONFIGURE_ON=	--with-libpcap-includes=${LOCALBASE}/include \
				--with-libpcap-libraries=${LOCALBASE}/lib
PORTS_PCAP_CONFIGURE_OFF=	--with-libpcap-includes=/usr/include \
				--with-libpcap-libraries=/usr/lib

PRELUDE_LIB_DEPENDS=		libprelude.so:${PORTSDIR}/security/libprelude
PRELUDE_CONFIGURE_ENABLE=	prelude
PRELUDE_CONFIGURE_ON=		--with-libprelude-prefix=${LOCALBASE}

JSON_LIB_DEPENDS=		libjansson.so:${PORTSDIR}/devel/jansson
JSON_CONFIGURE_OFF=		--with-libjansson-includes=${LOCALBASE}/include	\
				--with-libjansson-libraries=${LOCALBASE}/lib

NSS_LIB_DEPENDS=		libnss3.so:${PORTSDIR}/security/nss
NSS_CONFIGURE_ON=		--with-libnss-includes=${LOCALBASE}/include/nss/nss \
				--with-libnss-libraries=${LOCALBASE}/lib/nss \

TESTS_CONFIGURE_ENABLE=		unittests

SUB_FILES=	pkg-message

CONFIGURE_ARGS+=--enable-gccprotect \
		--with-libpcre-includes=${LOCALBASE}/include \
		--with-libpcre-libraries=${LOCALBASE}/lib \
		--with-libyaml-includes=${LOCALBASE}/include \
		--with-libyaml-libraries=${LOCALBASE}/lib \
		--with-libnet-includes=${LOCALBASE}/include/libnet11 \
		--with-libnet-libraries=${LOCALBASE}/lib/libnet11 \
		--with-libhtp-includes=${LOCALBASE}/include/ \
		--with-libhtp-libraries=${LOCALBASE}/lib \
		--localstatedir=/var/
CONFIGURE_ENV+=	ac_cv_path_HAVE_PYTHON_CONFIG=no

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet11-config
CONFIG_DIR?=	${ETCDIR}
CONFIG_FILES=	suricata.yaml classification.config reference.config
RULES_DIR=	${CONFIG_DIR}/rules
RULES_FILES=	decoder-events.rules dns-events.rules files.rules http-events.rules smtp-events.rules stream-events.rules tls-events.rules
LOGS_DIR?=	/var/log/${PORTNAME}

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64
.endif

pre-patch:
	${CP} ${FILESDIR}/ax_check_compile_flag.m4 ${WRKSRC}/m4

pre-install:
	@${REINPLACE_CMD} -e 's|/etc/suricata|${CONFIG_DIR}|g' ${WRKSRC}/suricata.yaml

post-install:
	${MKDIR} ${STAGEDIR}${CONFIG_DIR}
	${MKDIR} ${STAGEDIR}${RULES_DIR}
.for f in ${CONFIG_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${CONFIG_DIR}/${f}.sample
.endfor
.for f in ${RULES_FILES}
	${INSTALL_DATA} ${WRKSRC}/rules/${f} ${STAGEDIR}${RULES_DIR}/${f}
.endfor

TMPDIR?=	/tmp
TESTDIR=	${TMPDIR}/${PORTNAME}

regression-test: build
	${RM} -rf ${TESTDIR}
	${MKDIR} ${TESTDIR}
	cd ${WRKSRC}/src && ./suricata -u -l ${TESTDIR}
	${RM} -rf ${TESTDIR}

.include <bsd.port.post.mk>
